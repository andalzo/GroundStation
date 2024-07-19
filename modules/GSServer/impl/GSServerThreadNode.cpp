#include <utility>

#include "GSServer/GSServerThreadNode.h"

namespace GS
{
    GSServerThreadNode::GSServerThreadNode(TSML::TSMLContext<GS::CommonMsg> *context ,std::string node_id)
        : ThreadNode<CommonMsg, GSServerExceptions>(context, std::move(node_id))
    {
        status.port = 18500;
        status.state = GSServerState::Closed;
    }

    void GSServerThreadNode::SetStatus(const GS::GSServerStatus& status)
    {
        this->status = status;
    }

    void GSServerThreadNode::OnInitialize()
    {
        gs_server = std::make_unique<GSServer>(this, status.port);
        //TODO: Port can be adjusted by gui.
    }

    void GSServerThreadNode::OnRun()
    {
        switch(status.state)
        {
            case GSServerState::Closed:
                break;
            case GSServerState::Running:
            case GSServerState::FSClientConnected:
                OnServerUpdate();
                break;
            case GSServerState::Error:
                std::cout << "[GSServer][LOG-ERROR]: GSServer state is in error mode.";
                FinishLoop();
                break;
            default:
                break;
        }

    }

    void GSServerThreadNode::OnMessage(TSML::Message<GS::CommonMsg> msg)
    {
        switch(msg.header.id)
        {
            case CommonMsg::SetFSState:
                {
                  //TODO: Apply here a logic to transition from  TSML message to NL message
                  break;
                }
            case CommonMsg::FSStatus:
                {
                    break;
                }
            case CommonMsg::SetGSServerState:
                {
                    GSServerState new_state;
                    msg >> new_state;
                    switch(new_state)
                    {
                        case GSServerState::Closed:
                            {
                                if(gs_server->IsRunning())
                                {
                                    gs_server->Stop();
                                    status.state = GSServerState::Closed;
                                }
                                TSML::Message<GS::CommonMsg>  gs_status_message;
                                gs_status_message.header.id = GS::CommonMsg::GSServerStatus;
                                gs_status_message << status.state;
                                Send("gui",gs_status_message);
                            }
                        case GSServerState::Running:
                            {
                                if(!gs_server->IsRunning())
                                {
                                    gs_server->Start();
                                    status.state = GSServerState::Running;
                                }
                                TSML::Message<GS::CommonMsg>  gs_status_message;
                                gs_status_message.header.id = GS::CommonMsg::GSServerStatus;
                                gs_status_message << status.state;
                                Send("gui",gs_status_message);
                            }
                        case GSServerState::FSClientConnected:
                        case GSServerState::Error:
                        default:
                            break;
                    }
                    break;
                }
            case CommonMsg::GSServerStatus:
            default:
                break;

        }
    }

    void GSServerThreadNode::OnFinish()
    {
        if(gs_server->IsRunning())
        {
            gs_server->Stop();
        }
    }

    void GSServerThreadNode::OnException(const TSML::TSMLException<GSServerExceptions>& e)
    {

    }

    void GSServerThreadNode::OnServerUpdate()
    {
        if(gs_server->IsRunning())
        {
            gs_server->Update(-1,true);
        }
    }
}
