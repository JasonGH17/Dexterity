#pragma once

#include "http_header.h"

#include <string>
#include <vector>

namespace Dexterity::Server
{
    struct HTTPResponse
    {
        int statusCode;
        std::vector<HTTPHeader> headers;
        std::string content;

        std::string serialize()
        {
            std::string out = "HTTP/1.1 " + std::to_string(statusCode) + " OK" + "\n"; // Change "OK" with actual status code message later, lookup table maybe
            for (int i = 0; i < (int)headers.size(); i++)
            {
                out += headers[i].serialize();
            }
            out += "\n" + content;
            return out;
        };
    };
} // namespace Dexterity::Server
