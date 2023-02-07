#include "dexterity.h"

using namespace Dexterity::Server;

namespace Dexterity
{
    Application::Application() : m_server(HTTPServer("0.0.0.0", 8000)){}

    Application::~Application(){}
}
