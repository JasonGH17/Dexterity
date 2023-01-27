#include "dexterity.h"

namespace Dexterity
{
    Application::Application() : m_tcp(Server::TCPServer("0.0.0.0", 8000))
    {
        m_tcp.start();
    };

    Application::~Application(){};
}
