//
// Created by ehab on 2017-11-29.
//

#include <bits/unique_ptr.h>
#include "CClient.h"
#include "CConnection.h"

class CClient{
    std::unique_ptr<CConnection> connection;

};