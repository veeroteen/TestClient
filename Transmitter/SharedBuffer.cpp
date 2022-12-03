#include "SharedBuffer.h"
void SharedBuffer::set(const std::string &in)
{
    std::unique_lock<std::mutex> lk(mute);
    if(!data.empty())
    {
        socketCond.wait(lk);
    }
    data = in;
    lk.unlock();
    handCond->notify_one();
}

SharedBuffer::SharedBuffer(StringHandler &hand)
{
    handCond = hand.getCondition();
    hand.setControl(&data, &socketCond, &mute);
    pool = new boost::asio::thread_pool(1);
}

void SharedBuffer::call(const std::string &in)
{
    boost::asio::post(*pool,[in, this] { this->set(in); });
}

std::string* SharedBuffer::getData()
{
    return &data;
}

void SharedBuffer::end()
{
    pool->stop();
}