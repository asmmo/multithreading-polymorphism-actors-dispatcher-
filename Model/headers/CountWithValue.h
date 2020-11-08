//
// Created by asmmo on 9/23/2020.
//

#ifndef MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_COUNTWITHVALUE_H
#define MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_COUNTWITHVALUE_H


#include "Actor.h"

class CountWithValue : public Actor{
    const size_t increment;
public:
    CountWithValue( const std::string &, size_t);
    void increase() override;
    void decrease() override;
};


#endif //MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_COUNTWITHVALUE_H
