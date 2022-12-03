#include "Engine.h"

void Engine::start()
{
    SharedBuffer buffer(hand);
    input.setBuffer(&buffer);
    std::thread th(&StringHandler::start , &hand);
    input.start();
    buffer.end();
    hand.end();
    th.join();
}
