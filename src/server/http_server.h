#pragma once

#include "tcp_server.h"

namespace Dexterity::Server
{
    class HTTPServer : public TCPServer
    {
    public:
        HTTPServer(const char *hostname, int port);
        ~HTTPServer();

        virtual void respond();
    };
} // namespace Dexterity::Server
