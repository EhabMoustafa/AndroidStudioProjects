//
// Created by ehab on 2017-11-29.
//

#ifndef NEWP_CSERVER_H
#define NEWP_CSERVER_H

#include <vector>
#include "CConnection.h"
#include "CClient.h"

class CServer {
    std::vector<CClient> clients;
    CConnection server_;
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
public:
    CServer(int portno) {
        int n;
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            throw std::exception();
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);
        if (bind(sockfd, (struct sockaddr *) &serv_addr,
                 sizeof(serv_addr)) < 0)
            throw std::exception();
    }

    void listen(){
        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd,
                           (struct sockaddr *) &cli_addr,
                           &clilen);
        if (newsockfd < 0)
            throw std::exception();
        bzero(buffer, 1024);

        n = read(newsockfd, buffer, 1023);
        if (n < 0) throw std::exception();

    //    Mat image(690, 690, CV_8UC3, *buffer);
    //    imwrite("/home/securitas/images/prova.jpg", image);
        close(newsockfd);
        close(sockfd);

    }
};


#endif //NEWP_CSERVER_H
