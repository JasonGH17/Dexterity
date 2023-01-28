#pragma once

#ifdef _WIN32
#include <winsock2.h>
#else
#include <Sys/socket>
#include <Arpa/inet>
#endif

#include <string>

namespace Dexterity::Server
{
    class TCPServer
    {
    public:
        TCPServer(const char *hostname, int port);
        ~TCPServer();

        void start();

    protected:
        void setServerMessage(std::string msg);

    private:
        void acceptConnection();
        virtual void respond() = 0;

    private:
        const char *m_hostname;
        int m_port;
        long m_incomingMsg;
        struct sockaddr_in m_socketAddr;
        int m_socketAddrLen;
        std::string m_serverMsg;

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