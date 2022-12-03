#pragma once
#include "Context.h"

class Singleton {
private:

public:
    static Context* getInstance()
    {
        static Context instance;
        return &instance;
    }

};

