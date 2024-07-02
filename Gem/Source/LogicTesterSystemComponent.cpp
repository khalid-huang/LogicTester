
#include <AzCore/Serialization/SerializeContext.h>

#include "LogicTesterSystemComponent.h"

#include <LogicTester/LogicTesterTypeIds.h>

#include "AzCore/Console/ILogger.h"

namespace LogicTester
{
    AZ_COMPONENT_IMPL(LogicTesterSystemComponent, "LogicTesterSystemComponent",
        LogicTesterSystemComponentTypeId);

    void LogicTesterSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<LogicTesterSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void LogicTesterSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("LogicTesterService"));
    }

    void LogicTesterSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("LogicTesterService"));
    }

    void LogicTesterSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void LogicTesterSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    LogicTesterSystemComponent::LogicTesterSystemComponent()
    {
        if (LogicTesterInterface::Get() == nullptr)
        {
            LogicTesterInterface::Register(this);
        }
    }

    LogicTesterSystemComponent::~LogicTesterSystemComponent()
    {
        if (LogicTesterInterface::Get() == this)
        {
            LogicTesterInterface::Unregister(this);
        }
    }

    void LogicTesterSystemComponent::Init()
    {
    }

    void LogicTesterSystemComponent::Activate()
    {
        LogicTesterRequestBus::Handler::BusConnect();
    }

    void LogicTesterSystemComponent::Deactivate()
    {
        LogicTesterRequestBus::Handler::BusDisconnect();
        
    }
    void LogicTesterSystemComponent::OnTick(float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
        delayCount += deltaTime;
        // bigger than 5 second 
        if (delayCount > 5.0)
        {
            AZLOG_WARN("KAISEN::LOGIC, just for fun");
            delayCount = 0;
        }
    }
}
