#include "description.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<EquilateralTriangle*> triangles;
    vector <Hexagon*> hexagons;

    while (true) {
        cout << "What do you want to do?\n";
        cout << "1. Add new figure\n";
        cout << "2. Display all figures\n";
        cout << "3. Find total area\n";
        cout << "4. Find total perimeter\n";
        cout << "5. Sort figures\n";
        cout << "0. Quit\n\n";

        cout << "Enter a command: ";
        int command;
        cin >> command;
        cout << "\n";

        if (command == 1) {
            cout << "What figure do you want to add?\n";
            cout << "1. Equilateral triangle\n";
            cout << "2. Hexagon\n\n";

            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "Enter the coordinates of point1 (x, y): ";
                double x1, y1;
                cin >> x1 >> y1;
                cout << "Enter the coordinates of point2 (x, y): ";
                double x2, y2;
                cin >> x2 >> y2;
                triangles.push_back(new EquilateralTriangle({x1, y1}, {x2, y2}));
                cout << "The figure has been successfully added\n\n";
            }
            else if (choice == 2) {
                cout << "Enter the coordinates of point1 (x, y): ";
                double x1, y1;
                cin >> x1 >> y1;
                cout << "Enter the coordinates of point2 (x, y): ";
                double x2, y2;
                cin >> x2 >> y2;
                hexagons.push_back(new Hexagon({x1, y1}, {x2, y2}));
                cout << "The figure has been successfully added\n\n";
            }
        }
        else if (command == 2) {
            cout << "Enter a figure type:\n";
            cout << "1. Equilateral triangle\n";
            cout << "2. Hexagon\n\n";

            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                for (auto el: triangles) {
                    el->draw();
                }
                cout << "\n";
            }
            else if (choice == 2) {
                for (auto el: hexagons) {
                    el->draw();
                }
                cout << "\n";
            }
        }
        else if (command == 3) {
            cout << "Enter a figure type:\n";
            cout << "1. Equilateral triangle\n";
            cout << "2. Hexagon\n\n";

            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                double counter = 0;
                for (auto el: triangles) {
                    counter += el->square();
                }
                cout << "Total area: " << counter << "\n\n";
            }
            else if (choice == 2) {
                double counter = 0;
                for (auto el: hexagons) {
                    counter += el->square();
                }
                cout << "Total area: " << counter << "\n\n";
            }
        }
        else if (command == 4) {
            cout << "Enter a figure type:\n";
            cout << "1. Equilateral triangle\n";
            cout << "2. Hexagon\n\n";

            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                double counter = 0;
                for (auto el: triangles) {
                    counter += el->perimeter();
                }
                cout << "Total perimeter: " << counter << "\n\n";
            }
            else if (choice == 2) {
                double counter = 0;
                for (auto el: hexagons) {
                    counter += el->perimeter();
                }
                cout << "Total perimeter: " << counter << "\n\n";
            }
        }
        else if (command == 5) {
            cout << "What figures do you want to sort?\n";
            cout << "1. Equilateral triangle\n";
            cout << "2. Hexagon\n\n";

            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                if (!triangles.empty()) {
                    mergeSort(triangles, 0, triangles.size());
                    cout << "The figures were successfully sorted\n\n";
                }
                else {
                    cout << "There are not objects to sort\n\n";
                }
            }
            else if (choice == 2) {
                if (!triangles.empty()) {
                    mergeSort(hexagons, 0, hexagons.size());
                    cout << "The figures were successfully sorted\n\n";
                }
                else {
                    cout << "There are not objects to sort\n\n";
                }
            }
        }
        else if (command == 0) {
            break;
        }
        else {
            cout << "Wrong command\n\n";
        }
    }
    return 0;
}


