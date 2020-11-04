//
// Created by asmmo on 9/24/2020.
//

#include "View.h"

void View::printActorInfo(const Actor& actor){

    std::cout << "Name: " << actor.getName() << ", count field: " << actor.getCount()
        << ", and the total number of actors: " << actor.getCountOfActors() << std::endl;

}