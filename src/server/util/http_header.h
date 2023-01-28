#pragma once

#include <string>

namespace Dexterity::Server
{
    struct HTTPHeader
    {
        std::string key;
        std::string value;

        std::string serialize()
        {
            return key + ": " + value + "\n";
        };
    };

} // namespace Dexterity::Server