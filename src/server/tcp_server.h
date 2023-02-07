#pragma once

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include <string>

#include "threading/thread_pool.h"

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
        virtual std::string respond(std::string request) = 0;
        void serverJob(int socket);

    private:
        const char *m_hostname;
        int m_port;
        long m_incomingMsg;
        struct sockaddr_in m_socketAddr;
        int m_socketAddrLen;

        Threading::ThreadPool m_tp;

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