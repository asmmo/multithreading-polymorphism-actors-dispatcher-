//
// Created by asmmo on 9/23/2020.
//

#include "AutoIncrease.h"
AutoIncrease::AutoIncrease(const std::string & nameVal, long increment, size_t autoIncreaseVal):
        CountWithValue(nameVal, increment), autoIncrease{autoIncreaseVal}{}

void AutoIncrease::increase(){
    for(size_t  i{}; i< autoIncrease;++i) CountWithValue::increase();
}