#include "dexterity.h"

using namespace Dexterity::Server;

class NewController : public HTTPController
{
public:
    NewController(std::string path) : HTTPController(path)
    {
        handleGet("/test", handler(NewController::gettest1));
        handleGet("/test2", handler(NewController::gettest2));
    };

    const char *gettest1(HTTPRequest *req, HTTPResponse *res)
    {
        printf("test1");
        (void)req;

        res->statusCode = 200;
        res->headers.push_back(HTTPHeader{"Content-Type", "text/html"});
        return "<h1>Hello world</h1>";
    }

    const char *gettest2(HTTPRequest *req, HTTPResponse *res)
    {
        printf("test2");
        (void)req;

        res->statusCode = 200;
        res->headers.push_back(HTTPHeader{"Content-Type", "text/html"});
        return "<h1>Test Page 2</h1>";
    }
};

int main()
{
    Dexterity::Application app = Dexterity::Application();

    app.mapController<NewController>("/test");
    app.mapController<NewController>("/new");

    app.start();

    return 0;
}