#pragma once

namespace GS
{
    class GSBackend
    {
    public:
        GSBackend() = default;
        void Initialize();
        void Start();
        void Join();
    };
}
