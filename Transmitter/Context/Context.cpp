#include "Context.h"
Context::Context()
{
    io_service = new boost::asio::io_service();
    resolver = new udp::resolver(*io_service);
    query = new udp::resolver::query(udp::v4(), "localhost", "13");
    endpoint = new udp::endpoint(*(resolver->resolve(*query)));

    socket = new udp::socket(*io_service);
    socket->open(udp::v4());
}
Context::~Context()
{
    if(socket != nullptr)
    {
        delete socket;
    }
    if(endpoint != nullptr)
    {
        delete endpoint;
    }
    if(query != nullptr)
    {
        delete query;
    }
    if(resolver != nullptr)
    {
        delete resolver;
    }
    if(io_service != nullptr)
    {
        delete io_service;
    }
}
void Context::send(int n) const
{
    boost::array<int,1> buff = {n};
    socket->send_to(boost::asio::buffer(buff) , *endpoint);
}
