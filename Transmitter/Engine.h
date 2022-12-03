#include "SharedBuffer.h"
#include "InputString.h"
#include <thread>
#include "Context/Singleton.h"


class Engine {
    InputString input;
    StringHandler hand;
public:
    void start();
};
