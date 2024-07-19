#include "GSServer/GSServer.h"

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

    }

    void GSServer::OnMessage(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client, NL::Message<FGS::CommonMsg>& msg)
    {

    }

    void GSServer::OnClientDisconnect(std::shared_ptr<NL::Connection<FGS::CommonMsg>> client)
    {

    }
} // GS