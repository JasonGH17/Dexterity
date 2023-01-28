#pragma once

#include "server/http_server.h"

namespace Dexterity
{
    class Application
    {
    public:
        Application();
        ~Application();

    private:
        Server::HTTPServer m_http;
    };
}