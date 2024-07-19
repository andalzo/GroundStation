#pragma once
#include "GSServer/GSServerThreadNode.h"

namespace GS
{
    class GSBackend
    {
    public:
        explicit GSBackend(TSML::TSMLContext<CommonMsg>*);
        void Initialize();
        void Start();
        void Join();
    private:
        GSServerThreadNode gs_server_thread_node;
        TSML::TSMLContext<CommonMsg>* context{};
    };
}
