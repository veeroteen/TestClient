#include "StringHandler.h"

StringHandler::StringHandler()
{
    context = Singleton::getInstance();
}

void StringHandler::start()
{
    while (true) {
        std::unique_lock<std::mutex> lk(*mute);
        if(*data == "") {
            handCond.wait(lk);
        }
        if(flag)
        {
            break;
        }
        std::cout << *data << std::endl;
        std::string str = *data;
        data->clear();
        lk.unlock();
        socketCond->notify_one();
        int res = 0;
        for(auto &sym : str)
        {
            if(sym >= '0' && sym <= '9')
            {
                res += (sym - '0');
            }
        }
        context->send(res);
    }
}

void StringHandler::setControl(std::string* data , std::condition_variable* socketCond , std::mutex* mute)
{
    this->data = data;
    this->socketCond = socketCond;
    this->mute = mute;
}

std::condition_variable* StringHandler::getCondition()
{
    return &handCond;
}

void StringHandler::end()
{
    flag = true;
    handCond.notify_one();
}