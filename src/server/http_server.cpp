#include "http_server.h"

#include <functional>
#include <algorithm>

#include "util/http_header.h"
#include "util/http_request.h"
#include "util/http_response.h"
#include "http_controller.h"

namespace Dexterity::Server
{
    HTTPServer::HTTPServer(const char *hostname, int port) : TCPServer(hostname, port) {}
    HTTPServer::~HTTPServer() {}

    std::string HTTPServer::respond(std::string request)
    {
        HTTPRequest req = HTTPRequest::deserialize(request);
        HTTPResponse res = {404, std::vector<HTTPHeader>(0), ""};

        for (std::string path : *m_keys)
        {
            if (req.url.find(path) == 0)
            {
                HTTPController *controller = (*m_controllers)[path];
                controller->handleRequest(&req, &res);
            }
        }

        return res.serialize();
    }
} // namespace Dexterity::Server