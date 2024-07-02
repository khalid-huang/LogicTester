
#pragma once

#include <AzCore/Component/Component.h>

#include <LogicTester/LogicTesterBus.h>

#include "AzCore/Component/TickBus.h"

namespace LogicTester
{
    class LogicTesterSystemComponent
        : public AZ::Component
        , protected LogicTesterRequestBus::Handler
        , public AZ::TickBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(LogicTesterSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        LogicTesterSystemComponent();
        ~LogicTesterSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // LogicTesterRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::TickBus::Handler
        float delayCount = 0;
        void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;
        
        ////////////////////////////////////////////////////////////////////////
    };
}
