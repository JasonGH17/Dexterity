#include "http_controller.h"

#include <cstring>

namespace Dexterity::Server
{
    HTTPController::HTTPController(std::string path) : m_path(path) {}
    HTTPController::~HTTPController() {}

    HTTPResponse HTTPController::handleRequest(HTTPRequest *req, HTTPResponse *res)
    {
        HTTPHandler handle;
        if (req->method == "GET")
            handle = getHandlers[req->url];
        if (req->method == "POST")
            handle = postHandlers[req->url];
        if (req->method == "PATCH")
            handle = patchHandlers[req->url];
        if (req->method == "PUT")
            handle = putHandlers[req->url];
        if (req->method == "DELETE")
            handle = deleteHandlers[req->url];

        if (handle == NULL)
            return *res;

        res->content = handle(req, res);
        res->headers.push_back(HTTPHeader{"Content-Length", std::to_string(res->content.length())});

        return *res;
    }

    void HTTPController::handleGet(std::string path, HTTPHandler handler)
    {
        if (!getHandlers.count(m_path + path))
            getHandlers[m_path + path] = handler;
        else
            fprintf(stderr, "[CONTROLLER] \"%s\" GET handler already set... Skipping\n", path.c_str());
    }
    void HTTPController::handlePost(std::string path, HTTPHandler handler)
    {
        if (!postHandlers.count(m_path + path))
            postHandlers[m_path + path] = handler;
        else
            fprintf(stderr, "[CONTROLLER] \"%s\" POST handler already set... Skipping\n", path.c_str());
    }
    void HTTPController::handlePatch(std::string path, HTTPHandler handler)
    {
        if (!patchHandlers.count(m_path + path))
            patchHandlers[m_path + path] = handler;
        else
            fprintf(stderr, "[CONTROLLER] \"%s\" PATCH handler already set... Skipping\n", path.c_str());
    }
    void HTTPController::handlePut(std::string path, HTTPHandler handler)
    {
        if (!putHandlers.count(m_path + path))
            putHandlers[m_path + path] = handler;
        else
            fprintf(stderr, "[CONTROLLER] \"%s\" PUT handler already set... Skipping\n", path.c_str());
    }
    void HTTPController::handleDelete(std::string path, HTTPHandler handler)
    {
        if (!deleteHandlers.count(m_path + path))
            deleteHandlers[m_path + path] = handler;
        else
            fprintf(stderr, "[CONTROLLER] \"%s\" DELETE handler already set... Skipping\n", path.c_str());
    }
} // namespace Dexterity::Server
