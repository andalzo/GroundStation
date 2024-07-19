#pragma once
#include "FGSCommon/FGSCommon.h"
#include "NL/NL.h"

namespace GS
{
    class GSServerThreadNode;

    class GSServer final : public NL::ServerInterface<FGS::CommonMsg>
    {
    public:
        explicit GSServer(GSServerThreadNode* _tn, const uint16_t& port);
    protected:
        bool OnClientConnect(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client) override;
        void OnClientValidated(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client) override;
        void OnMessage(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client, NL::Message<FGS::CommonMsg>& msg) override;
        void OnClientDisconnect(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client) override;
    private:
        GSServerThreadNode* gs_server_thread_node{};
    };
} // GS


