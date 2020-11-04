//
// Created by asmmo on 9/24/2020.
//

#ifndef TESTB_CONTROLLER_H
#define TESTB_CONTROLLER_H
#include "View.h"
#include "Dispatcher.h"
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


#endif //TESTB_CONTROLLER_H
