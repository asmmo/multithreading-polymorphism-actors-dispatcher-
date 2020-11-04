//
// Created by asmmo on 9/23/2020.
//

#include "AutoDecrease.h"
AutoDecrease::AutoDecrease(const std::string & nameVal, long increment, size_t autoDecreaseVal):
    CountWithValue(nameVal, increment), autoDecrease{autoDecreaseVal}{}

void AutoDecrease::decrease(){
    for(size_t  i{}; i< autoDecrease;++i) CountWithValue::decrease();

}