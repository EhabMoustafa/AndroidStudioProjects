//
// Created by ehab on 2017-11-29.
//

#ifndef NEWP_CSERVER_H
#define NEWP_CSERVER_H

#include <vector>
#include "CConnection.h"
#include "CClient.h"

class CServer {

    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    std::list< std::pair<std::shared_ptr<CConnection>,std::shared_ptr<std::thread>> > clients;
public:
    CServer(int portno) {

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

  void read(char *buffer, size_t size) {

      while(1) {
          size_t n = ::read(newsockfd, buffer, size);
          if (n < 0) throw std::exception();
      }
  }


    void listen() {

        std::shared_ptr<std::thread> th(new std::thread(&CServer::waitConnection,this));

    }


    void waitConnection(){

        struct sockaddr_in cli_addr;

        while(1){
            ::listen(sockfd, 5);
            socklen_t clilen = sizeof(cli_addr);
            newsockfd = accept(sockfd,
                           (struct sockaddr *) &cli_addr,
                           &clilen);

            if (newsockfd < 0)
              throw std::exception();
            std::shared_ptr<CConnection> cc(new CConnection(cli_addr,newsockfd));
            std::shared_ptr<std::thread> th(new std::thread(&CConnection::writeImg,cc.get()) );
            clients.push_back(std::pair<std::shared_ptr<CConnection>,std::shared_ptr<std::thread>>(cc,th));
    }
    }


   void close(){
    //    Mat image(690, 690, CV_8UC3, *buffer);
    //    imwrite("/home/securitas/images/prova.jpg", image);

        ::close(sockfd);

    }
};


#endif //NEWP_CSERVER_H
