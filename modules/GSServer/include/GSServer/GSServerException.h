#pragma once
#include <cstdint>

namespace GS
{
    enum class GSServerExceptions : uint8_t
    {
        AsioException = 0,
        TSMLException
    };
}
