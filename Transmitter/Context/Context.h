#pragma once
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

class Context{
    boost::asio::io_service* io_service;
    udp::resolver* resolver;
    udp::resolver::query* query;
    udp::endpoint* endpoint;
    udp::socket* socket;
public:
    Context();
    ~Context();
    void send(int n) const;



};



