//
// Created by asmmo on 9/23/2020.
//

#ifndef MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_AUTOINCREASE_H
#define MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_AUTOINCREASE_H
#include "CountWithValue.h"

class AutoIncrease: public CountWithValue {
    size_t autoIncrease;
public:
    AutoIncrease(const std::string&, long, size_t);
    void increase();
};


#endif //MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_AUTOINCREASE_H
