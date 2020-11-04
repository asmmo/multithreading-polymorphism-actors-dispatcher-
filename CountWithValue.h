//
// Created by asmmo on 9/23/2020.
//

#ifndef TESTB_COUNTWITHVALUE_H
#define TESTB_COUNTWITHVALUE_H


#include "Actor.h"

class CountWithValue : public Actor{
    const size_t increment;
public:
    CountWithValue( const std::string &, size_t);
    void increase() override;
    void decrease() override;
};


#endif //TESTB_COUNTWITHVALUE_H
