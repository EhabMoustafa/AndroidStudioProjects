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


};


#endif //NEWP_CSERVER_H
