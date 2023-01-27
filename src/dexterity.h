#pragma once

#include "server/tcp_server.h"

namespace Dexterity
{
    class Application
    {
    public:
        Application();
        ~Application();

    private:
        Server::TCPServer m_tcp;
    };
}