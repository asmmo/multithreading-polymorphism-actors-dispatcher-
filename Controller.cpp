//
// Created by asmmo on 9/24/2020.
//

#include "Controller.h"

size_t Controller::getSizeTInput(Dispatcher& model, size_t to) {

    std::string input;
    size_t choice;
    bool validInput = false;

    while(!validInput) {
        try {
            std::cout << "\nPlease Enter a valid choice or mainMenu to back to it\nInput:\t";
            std::cin >> input;
            if(input == "mainMenu") return mainMenu(model);

            size_t takenChars;
            choice = std::stoul(input, &takenChars);
            if (choice > 0 && choice <= to && takenChars == input.size()) validInput = true;
        } catch (...) {
        }
    }

    return choice;
}

int Controller::mainMenu(Dispatcher& model){
    std::cout << "Hello!\n=================================================\n";
    std::cout << "1. Enter 1 to create an \"Actor\"\n";
    std::cout << "2. Enter 2 to get into a thread of a specific actor\n";
    std::cout << "3. Enter 3 to exit";

    auto choice = getSizeTInput(model, 3);

    switch (choice) {
        case 1: return creatActor(model);
        case 2: return getIntoActorThread(model);
        case 3: std::cout << "\nExiting...\n";
        default:    return 0;
    }

}


int Controller::creatActor(Dispatcher& model){
    std::cout << "\n==============================================\n";
    std::cout << "creating an actor\n\n";
    std::cout << "1. to create a default count\n";
    std::cout << "2. to create a count with value\n";
    std::cout << "3. to create an auto increase count\n";
    std::cout << "4. to create an auto decrease count\n";
    std::cout << "5. main menu\n";

    auto choice = getSizeTInput(model, 5);
    std::string name = "mainMenu";
    size_t increment{}; size_t interval{};


    while(name == "mainMenu"){
        std::cout << "\nInsert a valid name (note that mainMenu can't be a name):\t";
        std::cin >> name;
    }
    if(choice == 5) return mainMenu(model);

    if (choice == 2 || choice == 3 || choice == 4) {
        std::cout << "\nInsert An increment:";
        increment = getSizeTInput(model);
    }
    if (choice == 3 || choice == 4) {
        std::cout << "\nInsert An interval:";
        interval = getSizeTInput(model);
    }
    else;

    model.creatAndRunActor(name, choice, increment, interval);

    std::cout << "\n\nback to mani menu in 1 second...\n";
    std::this_thread::sleep_for(1s);

    return mainMenu(model);


}


int Controller::getIntoActorThread(Dispatcher& model){

    std::cout << "\n==============================================\n";
    std::cout << "Into an actor thread\n\n";
    std::cout << "1. to enter the Actor name\n";
    std::cout << "2. main menu\n";

    auto choice = getSizeTInput(model, 2);

    if(choice == 2) return mainMenu(model);
    std::string name;

    bool notFound = true;
    while(notFound) {
        std::cout << "\nPlease, insert a valid name or mainMenu to back to mainMenu:\t";
        std::cin >> name;
        if(name == "mainMenu") return mainMenu(model);
        notFound = !model.findActor(name);
    }

    const Actor& actor = model.getActor(name);

    std::cout << "\n==============================================\n";
    std::cout << "Into the thread of the actor of Id : " << actor.getName() << "\n\n";
    std::cout << "1. to get the info about the actor and the total actors number\n";
    std::cout << "2. to add task\n";
    std::cout << "3. main menu\n";

    choice = getSizeTInput(model, 3);

    if (choice == 3) return mainMenu(model);
    if (choice == 1) View::printActorInfo(actor);
    else if (choice == 2){
        std::cout << "\n==============================================\n";
        std::cout << "Into the thread of the actor of Id : " << actor.getName() << "\nChoose a task\n\n";
        std::cout << "1. to add an increase task\n";
        std::cout << "2. to add a decrease task\n";
        std::cout << "3. main menu\n";
        choice = getSizeTInput(model, 3);
        if (choice == 3) return mainMenu(model);
        if(choice == 1) model.addTaskToActor(actor.getName(), "increase");
        if(choice == 2) model.addTaskToActor(actor.getName(), "decrease");


    }

    std::cout << "\n\nback to mainMenu in 1 second...\n";
    std::this_thread::sleep_for(1s);

    return mainMenu(model);

}
