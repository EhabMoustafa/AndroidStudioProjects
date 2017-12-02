//
// Created by ehab on 2017-11-29.
//

#ifndef NEWP_CCONNECTION_H
#define NEWP_CCONNECTION_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <vector>
#include <list>
//#include <>
#include <thread>
#include <memory>
#include <deque>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class CConnection {
    int sockfd=-1;
    const int portno_;
    struct sockaddr_in addr_;
    struct hostent *server;
    CConnection();
    const std::string server_name_;
public:
    int getPortNo()const{return portno_;}
     inline void clearSockAddr(){}

    CConnection(    struct sockaddr_in addr, int sfd):addr_(addr),sockfd(sfd),portno_(0){
        if (sockfd < 0)
            throw std::exception();
    }

    CConnection(const std::string server_name,int portno):server_name_(std::move(server_name)),portno_(portno){
        if(portno<300||portno>10000)
            throw std::exception();
        char buffer[256];
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            throw std::exception();
        server = gethostbyname(server_name_.c_str());
        if (server == NULL) {
            throw std::exception();
        }
        bzero((char *) &addr_, sizeof(addr_));
        addr_.sin_family = AF_INET;
        bcopy((char *)server->h_addr,
              (char *)&addr_.sin_addr.s_addr,
              server->h_length);
        addr_.sin_port = htons(portno_);
    }
    bool connect(){
        return (::connect(sockfd,(struct sockaddr *) &addr_,sizeof(addr_)) >= 0);
     }
    bool write(char *&data,size_t size){
        size_t  n = ::write(sockfd, data, size);
        return (n >= 0);
    }

    void writeImg(){
        //size_t  n = ::write(sockfd, data, size);
        //return (n >= 0);
    }

    void read(char *&buffer, size_t size){
        size_t n = ::read(sockfd, buffer, size);
        if (n < 0) throw std::exception();
    }

bool closeConnection(){close(sockfd); }
~CConnection(){closeConnection();}
};


#endif //NEWP_CCONNECTION_H
