#ifndef _WIN32
#include "tcp_server.h"

#include <stdio.h>
#include <stdlib.h>

namespace Dexterity::Server
{
    TCPServer::TCPServer(const char *hostname, int port) : m_hostname(hostname), m_port(port), m_incomingMsg(), m_socketAddr(), m_socketAddrLen(sizeof(m_socketAddr)), m_clientSocket()
    {
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket < 0)
        {
            fprintf(stderr, "[TCP Sever] Unable to start server: \"socket\" function call failed...\n");
            exit(1);
        }

        m_socketAddr.sin_family = AF_INET;
        m_socketAddr.sin_port = htons(m_port);
        m_socketAddr.sin_addr.s_addr = inet_addr(hostname);

        if (bind(m_socket, (sockaddr *)&m_socketAddr, m_socketAddrLen) < 0)
        {
            fprintf(stderr, "[TCP Server] Unable to connect socket to address...\n");
            exit(1);
        }

        fprintf(stdout, "[TCP Server] Socket is ready.\n");
    }

    TCPServer::~TCPServer()
    {
        close(m_socket);
    }

    void TCPServer::start()
    {
        if (listen(m_socket, 20) < 0)
        {
            fprintf(stderr, "[TCP Server] Socket failed to listen on port %d\n", m_port);
            exit(1);
        }

        fprintf(stdout, "[TCP Server] Socket listening on address %s:%d\n", m_hostname, m_port);

        while (true)
        {
            acceptConnection();
        }
    }

    void TCPServer::setServerMessage(std::string msg)
    {
        m_serverMsg = msg;
    }

    void TCPServer::acceptConnection()
    {
        m_clientSocket = accept(m_socket, (sockaddr *)&m_socketAddr, (unsigned int*)&m_socketAddrLen);
        if (m_clientSocket < 0)
        {
            fprintf(stderr, "[TCP Server] Failed to accept request from address %s:%d\n", inet_ntoa(m_socketAddr.sin_addr), ntohs(m_socketAddr.sin_port));
        }

        char buff[1024] = {0};
        int nRecv = read(m_clientSocket, buff, 1024);
        if (nRecv < 0)
        {
            fprintf(stderr, "[TCP Server] Something went wrong while recieving a request...\n");
        }

        respond(buff);

        int bytesSent;
        long totalBytesSent = 0;
        while (totalBytesSent < (long)m_serverMsg.size())
        {
            bytesSent = write(m_clientSocket, m_serverMsg.c_str(), m_serverMsg.size());
            if (bytesSent < 0)
            {
                break;
            }
            totalBytesSent += bytesSent;
        }

        close(m_clientSocket);
    }
} // namespace Dexterity::Server

#endif