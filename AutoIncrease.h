//
// Created by asmmo on 9/23/2020.
//

#ifndef TESTB_AUTOINCREASE_H
#define TESTB_AUTOINCREASE_H
#include "CountWithValue.h"

class AutoIncrease: public CountWithValue {
    size_t autoIncrease;
public:
    AutoIncrease(const std::string&, long, size_t);
    void increase();
};


#endif //TESTB_AUTOINCREASE_H
