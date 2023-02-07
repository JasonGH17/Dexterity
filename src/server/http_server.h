#pragma once

#include <type_traits>
#include <unordered_map>
#include <vector>

#include "tcp_server.h"
#include "http_controller.h"

namespace Dexterity::Server
{
    class HTTPServer : public TCPServer
    {
    public:
        HTTPServer(const char *hostname, int port);
        ~HTTPServer();

        void bindControllerMap(std::unordered_map<std::string, HTTPController*> *controllers, std::vector<std::string> *keys)
        {
            m_controllers = controllers;
            m_keys = keys;
        }

        virtual std::string respond(std::string request);

    private:
        std::unordered_map<std::string, HTTPController*> *m_controllers;
        std::vector<std::string> *m_keys;
    };
} // namespace Dexterity::Server
