//
// Created by asmmo on 9/23/2020.
//

#ifndef MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_DEFAULTCOUNT_H
#define MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_DEFAULTCOUNT_H
#include "Actor.h"

class DefaultCount : public Actor{
public:
    explicit DefaultCount( const std::string &);
    void increase() override;
    void decrease() override;
};


#endif //MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_DEFAULTCOUNT_H
