#pragma once
#include <iostream>
#include <condition_variable>
#include <mutex>
#include "Context/Singleton.h"
class StringHandler
{
	std::string* data;
	std::condition_variable handCond;
	std::mutex* mute;
    std::condition_variable* socketCond;
    bool flag = false;
    Context* context;
public:
	StringHandler();

	void start();
    void setControl(std::string* data , std::condition_variable* socketCond , std::mutex* mute);
    std::condition_variable* getCondition();
    void end();



};

