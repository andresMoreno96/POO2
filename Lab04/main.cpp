#include <iostream>
#include <sstream>
#include <vector>
#include "Field.hpp"

using namespace std;

int main() {
//        Field field(10, 10, 1, 10);
//        field.play();

    vector<size_t> valuesGrid;

    cout << "Width Height nbVampires nbHumans: " << endl;
    do {
        string gridVals;
        getline(std::cin, gridVals);
        istringstream os(gridVals);

        int i;
        while (os >> i) {
            valuesGrid.push_back(i);
        }
        if (valuesGrid.size() == 4) {
            Field field(valuesGrid.at(0), valuesGrid.at(1),
                        valuesGrid.at(2), valuesGrid.at(3));

            string input = "";
            cout << "stats mode? y/n" << endl;
            do {
                getline(cin, input, '\n');

                if (input.size() > 0) {
                    char command = input[0];
                    if (command == 'y') {
                        field.playStats();
                    } else if (command == 'n') {
                        field.play();
                    } else {
                        cout << "### invalid input" << endl;
                    }
                }
            } while (input[0] != 'y' && input[0] != 'n');
        }
    } while (valuesGrid.size() < 4);


    return EXIT_SUCCESS;
}
