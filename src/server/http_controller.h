#pragma once

#include <functional>
#include <vector>
#include <unordered_map>

#include "util/http_response.h"
#include "util/http_request.h"

#define handler(function) std::bind(&function, this, std::placeholders::_1, std::placeholders::_2)

namespace Dexterity::Server
{
    typedef std::function<const char *(HTTPRequest *, HTTPResponse *)> HTTPHandler;

    class HTTPController
    {
        friend class HTTPServer;

    public:
        HTTPController(std::string path);
        ~HTTPController();

        std::string m_path;

    protected:
        HTTPResponse handleRequest(HTTPRequest *req, HTTPResponse *res);

    protected:
        void handleGet(std::string path, HTTPHandler handler);
        void handlePost(std::string path, HTTPHandler handler);
        void handlePatch(std::string path, HTTPHandler handler);
        void handlePut(std::string path, HTTPHandler handler);
        void handleDelete(std::string path, HTTPHandler handler);

    private:
        std::unordered_map<std::string, HTTPHandler> getHandlers;
        std::unordered_map<std::string, HTTPHandler> postHandlers;
        std::unordered_map<std::string, HTTPHandler> patchHandlers;
        std::unordered_map<std::string, HTTPHandler> putHandlers;
        std::unordered_map<std::string, HTTPHandler> deleteHandlers;

        // TODO: Implement handle(x) methods for the following maps
        std::unordered_map<std::string, HTTPHandler> headHandlers;
        std::unordered_map<std::string, HTTPHandler> connectHandlers;
        std::unordered_map<std::string, HTTPHandler> optionsHandlers;
    };
} // namespace Dexterity::Server