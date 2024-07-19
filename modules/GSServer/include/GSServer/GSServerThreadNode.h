#pragma once
#include "GSServer.h"
#include "TSML.h"
#include "GSServerException.h"

namespace GS
{
    class GSServerThreadNode final : public TSML::ThreadNode<GS::CommonMsg, GSServerExceptions>
    {
    public:
        explicit GSServerThreadNode(TSML::TSMLContext<GS::CommonMsg> *context ,std::string node_id = "GSServer");
        void SetStatus(const GS::GSServerStatus& status);

    protected:
        void OnInitialize() override;
        void OnRun() override;
        void OnMessage(TSML::Message<GS::CommonMsg> msg) override;
        void OnFinish() override;
        void OnException(const TSML::TSMLException<GSServerExceptions>& e) override;

    private:
        void OnServerUpdate();
        GS::GSServerStatus status;
        std::unique_ptr<GSServer> gs_server;
    };
}
