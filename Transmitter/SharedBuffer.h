#pragma once
#include <string>
#include <condition_variable>
#include <mutex>
#include "StringHandler.h"
#include "boost/asio/post.hpp"
#include "boost/asio/thread_pool.hpp"



class SharedBuffer
{
	std::string data;
	std::mutex mute;
    std::condition_variable *handCond;
    std::condition_variable socketCond;
    boost::asio::thread_pool *pool;

    void set(const std::string &in);

public:
	SharedBuffer(StringHandler &hand);
    void call(const std::string &in);
    std::string* getData();
    void end();
};
