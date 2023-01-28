#pragma once

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
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
        virtual void respond(std::string request) = 0;

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
        int m_socket;
        int m_clientSocket;
#endif
    };
} // namespace Dexterity::Server