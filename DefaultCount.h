//
// Created by asmmo on 9/23/2020.
//

#ifndef TESTB_DEFAULTCOUNT_H
#define TESTB_DEFAULTCOUNT_H
#include "Actor.h"

class DefaultCount : public Actor{
public:
    explicit DefaultCount( const std::string &);
    void increase() override;
    void decrease() override;
};


#endif //TESTB_DEFAULTCOUNT_H
