
#pragma once

#include <LogicTester/LogicTesterTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace LogicTester
{
    class LogicTesterRequests
    {
    public:
        AZ_RTTI(LogicTesterRequests, LogicTesterRequestsTypeId);
        virtual ~LogicTesterRequests() = default;
        // Put your public methods here
    };

    class LogicTesterBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using LogicTesterRequestBus = AZ::EBus<LogicTesterRequests, LogicTesterBusTraits>;
    using LogicTesterInterface = AZ::Interface<LogicTesterRequests>;

} // namespace LogicTester
