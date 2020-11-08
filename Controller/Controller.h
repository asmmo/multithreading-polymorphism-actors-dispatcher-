//
// Created by asmmo on 9/24/2020.
//

#ifndef MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_CONTROLLER_H
#define MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_CONTROLLER_H
#include "../View/View.h"
#include "../Model/headers/Dispatcher.h"
#include <chrono>

using namespace std::chrono_literals;

class Controller {
    View view;

    static size_t getSizeTInput(Dispatcher& , size_t = std::numeric_limits<size_t>::max());

    static int creatActor(Dispatcher&);

    static int getIntoActorThread(Dispatcher&);

public:

    static int mainMenu(Dispatcher&);

};


#endif //MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_CONTROLLER_H
