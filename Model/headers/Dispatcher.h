//
// Created by asmmo on 9/23/2020.
//

#ifndef MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_DISPATCHER_H
#define MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_DISPATCHER_H

#include <map>
#include <queue>
#include "AutoDecrease.h"
#include "AutoIncrease.h"
#include "DefaultCount.h"
#include "Worker.h"

class Dispatcher {
    std::map<std::string, std::unique_ptr<Worker>> workers;
public:
    void creatAndRunActor(const std::string& name, size_t actorType, size_t increment = 0, size_t interval = 0);

    void addTaskToActor(const std::string & name, const std::string & );

    bool findActor(const std::string name) const ;

    const Actor& getActor(const std::string& actorName)const;

};


#endif //MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_DISPATCHER_H
