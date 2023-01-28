#include "http_server.h"

#include "util/http_header.h"
#include "util/http_response.h"

namespace Dexterity::Server
{
    HTTPServer::HTTPServer(const char *hostname, int port) : TCPServer(hostname, port)
    {
        start();
    }
    HTTPServer::~HTTPServer() {}

    void HTTPServer::respond()
    {
        std::vector<HTTPHeader> headers;
        headers.push_back({"Content-Type", "text/html"});
        headers.push_back({"Content-Length", "21"});

        HTTPResponse res = HTTPResponse{
            200,
            headers,
            "<h1>Hello world!</h1>"};

        setServerMessage(res.serialize());
    }
} // namespace Dexterity::Server