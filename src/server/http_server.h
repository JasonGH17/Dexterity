#pragma once

#include "tcp_server.h"

namespace Dexterity::Server
{
    class HTTPServer : public TCPServer
    {
    public:
        HTTPServer(const char *hostname, int port);
        ~HTTPServer();

        virtual void respond(std::string request);
    };
} // namespace Dexterity::Server
