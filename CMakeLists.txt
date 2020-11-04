cmake_minimum_required(VERSION 3.17)
project(multithreading-polymorphism-actors-dispatcher-MVC)

set(CMAKE_CXX_STANDARD 20)
set( -Wall)

add_executable(TestB main.cpp Actor.cpp Actor.h CountWithValue.cpp CountWithValue.h DefaultCount.cpp DefaultCount.h
        AutoIncrease.cpp AutoIncrease.h AutoDecrease.cpp AutoDecrease.h Dispatcher.cpp Dispatcher.h
        Worker.cpp Worker.h View.cpp View.h Controller.cpp Controller.h)
