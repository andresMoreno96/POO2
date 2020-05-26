//
// Created by simon on 22.05.20.
//

#include "RandomMoveAction.hpp"

RandomMoveAction::RandomMoveAction(Humanoid* humanoid) : MoveAction(humanoid) {}

void RandomMoveAction::execute(Field &f) {

    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 7);

    int randNumb = distribution(rd);
    bool canMove = false;

    do {
        switch (randNumb) {
            case 0: // North-West
                canMove = f.moveHumanoid(*humanoid, humanoid->getX() - 1, humanoid->getY() - 1);
                break;
            case 1: // North
                canMove = f.moveHumanoid(*humanoid, humanoid->getX(), humanoid->getY() - 1);
                break;
            case 2: // North-East
                canMove = f.moveHumanoid(*humanoid, humanoid->getX() + 1, humanoid->getY() - 1);
                break;
            case 3: // West
                canMove = f.moveHumanoid(*humanoid, humanoid->getX() - 1, humanoid->getY());
                break;
            case 4: // East
                canMove = f.moveHumanoid(*humanoid, humanoid->getX() + 1, humanoid->getY());
                break;
            case 5: // South-West
                canMove = f.moveHumanoid(*humanoid, humanoid->getX() - 1, humanoid->getY() + 1);
                break;
            case 6: // South
                canMove = f.moveHumanoid(*humanoid, humanoid->getX(), humanoid->getY() + 1);
                break;
            case 7: // South-East
                canMove = f.moveHumanoid(*humanoid, humanoid->getX() + 1, humanoid->getY() + 1);
                break;

        }
        if (!canMove) {
            randNumb = (randNumb + 1) % 8;
        }
    } while (!canMove);


}
