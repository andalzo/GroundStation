#include "GSServer/GSServer.h"

#include <GSServer/GSServerThreadNode.h>

namespace GS
{
    GSServer::GSServer(GSServerThreadNode* _tn, const uint16_t& port) : ServerInterface<FGS::CommonMsg>(port)
    {
        gs_server_thread_node = _tn;
    }

    bool GSServer::OnClientConnect(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client)
    {
        return true;
    }

    void GSServer::OnClientValidated(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client)
    {
        NL::Message<FGS::CommonMsg> msg;
        msg.header.id = FGS::CommonMsg::FSValidated;
        MessageClient(client, msg);

        GSServerStatus status = gs_server_thread_node->GetStatus();
        status.state = GSServerState::FSClientConnected;
        gs_server_thread_node->SetStatus(status);

        TSML::Message<CommonMsg> msg2;
        msg2.header.id = CommonMsg::GSServerStatus;
        msg2 << status.state;
        gs_server_thread_node->Send("gui",msg2);
    }

    void GSServer::OnMessage(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client, NL::Message<FGS::CommonMsg>& msg)
    {

    }

    void GSServer::OnClientDisconnect(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client)
    {

    }
} // GS