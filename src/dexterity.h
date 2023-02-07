#pragma once

#include <type_traits>

#include "server/http_server.h"
#include "server/http_controller.h"

namespace Dexterity
{
    class Application
    {
    public:
        Application();
        ~Application();

        template <class controller>
        void mapController(std::string path)
        {
            static_assert(std::is_base_of<Server::HTTPController, controller>::value);

            m_keys.push_back(path);
            m_controllers[path] = new controller(path);
        }

        void start() {
            m_server.bindControllerMap(&m_controllers, &m_keys);
            m_server.start();
        }

        Server::HTTPServer m_server;

    private:
        std::unordered_map<std::string, Server::HTTPController*> m_controllers;
        std::vector<std::string> m_keys;
    };
}