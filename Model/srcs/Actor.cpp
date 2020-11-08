//
// Created by asmmo on 9/23/2020.
//

#include <Actor.h>
Actor::Actor(const std::string & nameArg):count{0}, name{nameArg}{
    ++countOfActors;
}

size_t Actor::getCountOfActors() const {
    return countOfActors;
}

std::string Actor::getName()const{
    return name;
}
long long Actor::getCount() const{
    return count.load();
}