
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "LogicTesterSystemComponent.h"

#include <LogicTester/LogicTesterTypeIds.h>

namespace LogicTester
{
    class LogicTesterModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(LogicTesterModule, LogicTesterModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(LogicTesterModule, AZ::SystemAllocator);

        LogicTesterModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                LogicTesterSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<LogicTesterSystemComponent>(),
            };
        }
    };
}// namespace LogicTester

AZ_DECLARE_MODULE_CLASS(Gem_LogicTester, LogicTester::LogicTesterModule)
