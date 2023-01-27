#pragma once

#ifdef _WIN32
#include <winsock2.h>
#else
#include <Sys/socket>
#include <Arpa/inet>
#endif

namespace Dexterity::Server
{
    class TCPServer
    {
    public:
        TCPServer(const char *hostname, int port);
        ~TCPServer();

        void start();

    private:
        void acceptConnection();

    private:
        const char *m_hostname;
        int m_port;
        long m_incomingMsg;
        struct sockaddr_in m_socketAddr;
        int m_socketAddrLen;
        const char *m_serverMsg = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 100\n\n<!DOCTYPE html><html lang=\"en\"><body><h1> HOME </h1><p> Hello from your Server :) </p></body></html>";
        int m_serverMsgLen = 161;

#ifdef _WIN32
        // Windows members
        WSAData m_wsaData;
        SOCKET m_socket;
        SOCKET m_clientSocket;
#else
        // Linux members
#endif
    };
} // namespace Dexterity::Server