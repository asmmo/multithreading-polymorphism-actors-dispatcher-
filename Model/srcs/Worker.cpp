//
// Created by asmmo on 9/23/2020.
//

#include <Worker.h>

Worker::Worker(std::unique_ptr<Actor> && actor_):tasksCV{ new std::condition_variable }, tasksMutex{new std::mutex},
    tasks{}, actor{std::move(actor_)}, workerThread{}, tasksFinishedFlag{ new std::atomic_bool{false}}
{

    workerThread = std::thread{
            [&]{
                while(!(*tasksFinishedFlag)){
                    {
                        std::unique_lock lk{ *tasksMutex };
                        tasksCV -> wait(lk, [&] { return *tasksFinishedFlag || !tasks.empty(); });
                    }
                    while(true){

                        {
                            if(!*tasksFinishedFlag) std::lock_guard lk { *tasksMutex };
                            if (tasks.empty()) break;
                        }

                        void(Actor::* task)();
                        {
                            std::lock_guard lk { *tasksMutex };
                            task = tasks.front();
                            tasks.pop();
                        }
                        (actor.get()->*task)();
                    }
                }
            }
    };

}

void Worker::addTask(void (Actor::* task)()) {

    {
        std::lock_guard lk{ *tasksMutex };
        tasks.emplace(task);
    }
    tasksCV -> notify_all();
}

const Actor& Worker::getActor()const{
    return *actor;
}

Worker::~Worker(){

    {
        std::lock_guard lk { *tasksMutex };
        *tasksFinishedFlag = true;
    }

    tasksCV -> notify_all();
    workerThread.join();
}