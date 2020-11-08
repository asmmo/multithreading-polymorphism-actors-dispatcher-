//
// Created by asmmo on 9/23/2020.
//

#include <Dispatcher.h>


//
// Created by asmmo on 9/23/2020.
//

void Dispatcher::creatAndRunActor(const std::string& actorName, size_t actorType, size_t increment, size_t interval){

        if (findActor(actorName))
            throw std::runtime_error{std::string{"\nThere is already actor named "}+ actorName};

        std::unique_ptr<Actor> toBeInsertedActor;

        switch (actorType) {
            case 1:
                toBeInsertedActor = std::make_unique<DefaultCount>(actorName);
                break;
            case 2:
                toBeInsertedActor = std::make_unique<CountWithValue>(actorName, increment);
                break;
            case 3:
                toBeInsertedActor = std::make_unique<AutoIncrease>(actorName, increment, interval);
                break;
            case 4:
                toBeInsertedActor = std::make_unique<AutoDecrease>(actorName, increment, interval);
                break;
            default:
                throw std::runtime_error{std::string{"\nInvalid type "}};
        }

        workers.emplace(actorName, new Worker{std::move(toBeInsertedActor)});
    }

void Dispatcher::addTaskToActor(const std::string & actorName, const std::string & taskName ){
    auto it = workers.find(actorName);
    if( it == workers.end()) throw std::runtime_error{std::string{"\nThere is no actor named "}+ actorName};

    if(taskName == "increase") it -> second -> addTask(&Actor::increase);
    else if(taskName == "decrease") it -> second -> addTask(&Actor::decrease);
    else throw std::runtime_error{std::string{"\nThere is no task named "}+ taskName};

}


const Actor & Dispatcher::getActor(const std::string& actorName)const{
        auto it = workers.find(actorName);
        if( it == workers.end()) throw std::runtime_error{std::string{"\nThere is no actor named "}+ actorName};
        return it -> second -> getActor();

}

bool Dispatcher::findActor(const std::string name) const{
    return workers.find(name) != workers.end();
}