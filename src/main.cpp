//header files
#include "../header/GameController.h"

//libraries
#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));

    GameController controller;
    controller.startGame();

    return 0;

}