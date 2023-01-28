#include "http_server.h"

#include "util/http_header.h"
#include "util/http_request.h"
#include "util/http_response.h"

namespace Dexterity::Server
{
    HTTPServer::HTTPServer(const char *hostname, int port) : TCPServer(hostname, port)
    {
        start();
    }
    HTTPServer::~HTTPServer() {}

    void HTTPServer::respond(std::string request)
    {
        HTTPRequest req = HTTPRequest::deserialize(request);

        std::vector<HTTPHeader>
            headers;
        headers.push_back({"Content-Type", "text/html"});

        char *msg;
        if (req.url == "/")
        {
            headers.push_back({"Content-Length", "24"});
            msg = "<h1>C++ HTTP Server</h1>";
        }
        else if (req.url == "/hello")
        {
            headers.push_back({"Content-Length", "17"});
            msg = "<h1>Hello :)</h1>";
        }
        else
        {
            headers.push_back({"Content-Length", "22"});
            msg = "<h1>Invalid route</h1>";
        }

        HTTPResponse res = HTTPResponse{
            200,
            headers,
            msg};

        setServerMessage(res.serialize());
    }
} // namespace Dexterity::Server