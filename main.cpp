
#include "Controller/Controller.h"
using namespace std::chrono_literals;
int main() {

    Dispatcher model;
    Controller controller;
    return Controller::mainMenu(model);

}
