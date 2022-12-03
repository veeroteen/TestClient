#include "InputString.h"

void InputString::setBuffer(SharedBuffer* buffer)
{
    this->buffer = buffer;
}

void InputString::start()
{

    while(true){
        std::string str;
        std::cout << "enter message\n";
        std::cin >> str;
        if(str == "exit")
        {
            break;
        }
        if(str.length() > 64 )
        {
            std::cerr << "input out of range\n";
            continue;
        }
        try {
            for (auto &sym: str) {
                if (sym < '0' || sym > '9') {
                    throw std::invalid_argument("input has to be numeric only\n");
                }

            }
        }
        catch(std::invalid_argument e)
        {
            std::cerr << e.what();
            continue;
        }


        std::sort(str.begin(),str.end(),std::greater<int>());

        std::string request;
        for(auto &sym : str)
        {
            if((sym - 0)%2 == 0)
            {
                request += "KB";

            }
            else
            {
                request += sym;
            }

        }
        buffer->call(request);

    }
}