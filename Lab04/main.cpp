#include <iostream>
#include <sstream>
#include <vector>
#include "Field.hpp"

using namespace std;

int main() {
//        Field field(10, 10, 4, 6);
//        field.play();

    vector<size_t> valuesGrid;
    bool statsOnly = false;

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
            field.play();
        }
    } while (valuesGrid.size() < 4);


    return EXIT_SUCCESS;
}
