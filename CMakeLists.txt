cmake_minimum_required(VERSION 3.17)
project(multithreading-polymorphism-actors-dispatcher-MVC)
set(CMAKE_CXX_STANDARD 20)
add_executable(multithreading-polymorphism-actors-dispatcher-MVC main.cpp
        Model/srcs/Actor.cpp
        Model/srcs/AutoDecrease.cpp
        Model/srcs/AutoIncrease.cpp
        Model/srcs/CountWithValue.cpp
        Model/srcs/DefaultCount.cpp
        Model/srcs/Dispatcher.cpp
        Model/srcs/Worker.cpp

        View/View.cpp

        Controller/Controller.cpp
        )

include_directories(multithreading-polymorphism-actors-dispatcher-MVC PUBLIC Model/headers/)
include_directories(multithreading-polymorphism-actors-dispatcher-MVC PUBLIC View/)
include_directories(multithreading-polymorphism-actors-dispatcher-MVC PUBLIC Controller/)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU OR CMAKE_CXX_COMPILER_ID MATCHES Clang)
    target_link_libraries(multithreading-polymorphism-actors-dispatcher-MVC pthread)
    add_compile_options(-Wall -Wextra -Werror -O3 -pedantic)
    elseif(MSVC)
    add_compile_options(/W4 /EHsc)
endif()