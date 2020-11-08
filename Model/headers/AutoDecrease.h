//
// Created by asmmo on 9/23/2020.
//

#ifndef MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_AUTODECREASE_H
#define MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_AUTODECREASE_H
#include "CountWithValue.h"

class AutoDecrease: public CountWithValue {
    size_t autoDecrease;
public:
    AutoDecrease(const std::string&, long, size_t);
    void decrease();

};


#endif //MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_AUTODECREASE_H
