cmake_minimum_required(VERSION 3.22)
project(ClientTest)
set(CMAKE_CXX_STANDARD 17)

include_directories (Transmitter ${CMAKE_CURRENT_SOURCE_DIR}/Transmitter)

include(FetchContent)
FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG 32da69a36f84c5255af8a994951918c258bac601
)

FetchContent_MakeAvailable(boost)



add_executable(ClientTest main.cpp Transmitter/InputString.h Transmitter/SharedBuffer.h Transmitter/StringHandler.h
        Transmitter/InputString.cpp Transmitter/SharedBuffer.cpp Transmitter/StringHandler.cpp
        Transmitter/Context/Context.cpp Transmitter/Context/Context.h Transmitter/Context/Singleton.h Transmitter/Engine.cpp Transmitter/Engine.h)


target_link_libraries(ClientTest PRIVATE Boost::asio wsock32 ws2_32)

