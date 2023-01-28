#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "http_header.h"

namespace Dexterity::Server
{
    struct HTTPRequest
    {
        std::string method;
        std::string url;
        std::string version;
        std::vector<HTTPHeader> headers;
        std::string body;

        static HTTPRequest deserialize(std::string req)
        {
            HTTPRequest out = {};

            if (req == "")
                return out;

            std::stringstream stream(req);

            std::getline(stream, out.method, ' ');
            std::getline(stream, out.url, ' ');
            std::getline(stream, out.version, '\n');

            std::string line;
            while (std::getline(stream, line, '\n'))
            {
                std::string key = line.substr(0, line.find(": "));
                line.erase(0, line.find(": ") + 2);
                std::string value = line;
                if (key == "" || value == "")
                    break;
                out.headers.push_back({key, value});
            }

            return out;
        }
    };

} // namespace Dexterity::Server
