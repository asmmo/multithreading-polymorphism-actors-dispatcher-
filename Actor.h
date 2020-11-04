//
// Created by asmmo on 9/23/2020.
//

#ifndef TESTB_ACTOR_H
#define TESTB_ACTOR_H

#include <string>
#include <atomic>

class Actor{

    std::string name;
    static inline size_t countOfActors{};

protected:
    std::atomic<long long> count;

public:

    explicit Actor(const std::string &);

    [[nodiscard]] size_t getCountOfActors() const;
    [[nodiscard ]] std::string getName()const;
    [[nodiscard ]] long long getCount()const;

    virtual void increase() = 0;
    virtual void decrease() = 0;

};



#endif //TESTB_ACTOR_H
