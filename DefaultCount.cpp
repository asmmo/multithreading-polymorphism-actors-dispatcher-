//
// Created by asmmo on 9/23/2020.
//

#include "DefaultCount.h"

DefaultCount::DefaultCount( const std::string & stringArg):Actor{stringArg}{}

void DefaultCount::increase(){
    ++count;
}

void DefaultCount::decrease(){
    --count;
}