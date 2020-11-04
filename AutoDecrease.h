//
// Created by asmmo on 9/23/2020.
//

#ifndef TESTB_AUTODECREASE_H
#define TESTB_AUTODECREASE_H
#include "CountWithValue.h"

class AutoDecrease: public CountWithValue {
    size_t autoDecrease;
public:
    AutoDecrease(const std::string&, long, size_t);
    void decrease();

};


#endif //TESTB_AUTODECREASE_H
