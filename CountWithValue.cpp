//
// Created by asmmo on 9/23/2020.
//

#include "CountWithValue.h"

CountWithValue::CountWithValue(const std::string & stringArg, size_t val):Actor{stringArg}, increment{val}{}
void CountWithValue::increase(){
    count += increment;
}

void CountWithValue::decrease(){
    count -= increment;
}
