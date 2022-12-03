#pragma once
#include "SharedBuffer.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
class InputString
{
	SharedBuffer* buffer;

public:
    InputString() = default;
    void setBuffer(SharedBuffer* buffer);
    void start();
};

