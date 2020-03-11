#include "Socket.h"
#include "Utility.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <stdexcept>

#include <iostream>

BaseSocket::BaseSocket(int socketId)
    : socketId(socketId) {
    if(socketId == -1) {
        throw std::runtime_error(); // TODO: what to throw
    }
}

BaseSocket::~BaseSocket() {
    if(socketId == invalidSocketId) {
        close();
    }
    try {
        close();
    }
    catch (...) {

    }
}

BaseSocket::close() {
    if(socketId == invalidSocketId)  {
        throw std::logic_error() //todo
    }
}