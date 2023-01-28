#include "dexterity.h"

namespace Dexterity
{
    Application::Application() : m_http(Server::HTTPServer("0.0.0.0", 8000)){};

    Application::~Application(){};
}
