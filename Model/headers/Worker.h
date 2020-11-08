//
// Created by asmmo on 9/23/2020.
//

#ifndef MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_WORKER_H
#define MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_WORKER_H

#include <mutex>
#include <queue>
#include <condition_variable>
#include <thread>
#include "Actor.h"


class Worker {

    std::unique_ptr<std::condition_variable> tasksCV;
    std::unique_ptr<std::mutex> tasksMutex;
    std::queue<void (Actor::*)()> tasks;
    std::unique_ptr<Actor> actor;
    std::thread workerThread;
    std::unique_ptr<std::atomic_bool> tasksFinishedFlag;

public:

    explicit Worker(std::unique_ptr<Actor>&&);
    Worker(Worker &&)noexcept = default;
    Worker& operator=(Worker &&)noexcept = delete;

    [[nodiscard]]const Actor& getActor()const;
    void addTask(void(Actor::*)());
    ~Worker();
};



#endif //MULTITHREADING_POLYMORPHISM_ACTORS_DISPATCHER_MVC_WORKER_H
