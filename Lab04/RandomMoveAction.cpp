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
            case 0:
                canMove = f.moveHumanoid(*humanoid, humanoid->getX() - 1, humanoid->getY() - 1);
                break;

            case 1:

                canMove = f.moveHumanoid(*humanoid, humanoid->getX(), humanoid->getY() - 1);
                break;
            case 2:

                canMove = f.moveHumanoid(*humanoid, humanoid->getX() + 1, humanoid->getY() - 1);
                break;
            case 3:

                canMove = f.moveHumanoid(*humanoid, humanoid->getX() - 1, humanoid->getY());
                break;
            case 4:

                canMove = f.moveHumanoid(*humanoid, humanoid->getX() + 1, humanoid->getY());
                break;
            case 5:

                canMove = f.moveHumanoid(*humanoid, humanoid->getX() - 1, humanoid->getY() + 1);
                break;
            case 6:

                canMove = f.moveHumanoid(*humanoid, humanoid->getX(), humanoid->getY() + 1);
                break;
            case 7:

                canMove = f.moveHumanoid(*humanoid, humanoid->getX() + 1, humanoid->getY() + 1);
                break;

        }
        if (!canMove) {
            randNumb = (randNumb + 1) % 8;
        }
    } while (!canMove);


}
