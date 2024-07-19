#include "GSBackend.h"

namespace GS
{
    GSBackend::GSBackend(TSML::TSMLContext<CommonMsg>* context) : gs_server_thread_node(context, "GSServer")
    {
        this->context = context;
    }

    void GSBackend::Initialize()
    {
        gs_server_thread_node.InitializeLoop();
    }

    void GSBackend::Start()
    {
        gs_server_thread_node.StartLoop();
    }

    void GSBackend::Join()
    {
        if(gs_server_thread_node.IsJoinable())
        {
            gs_server_thread_node.Join();
        }
    }
}


