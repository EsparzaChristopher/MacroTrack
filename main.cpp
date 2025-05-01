#include "food.h"
#include <iostream>
using namespace std;

int main() {
    food foodList;  // Create an instance of the food class
    int choice;
    string filename;
    string foodName;

    do {
        cout << "\n======== Food Tracker Menu ========\n";
        cout << "1. Add Food Item\n";
        cout << "2. Remove Food Item\n";
        cout << "3. Display All Foods\n";
        cout << "4. Display Totals (Protein/Carbs/Fat)\n";
        cout << "5. Search for a Food Item\n";
        cout << "6. Sort Foods Alphabetically\n";
        cout << "7. Save to File\n";
        cout << "8. Load from File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore leftover newline

        switch (choice) {
            case 1:
                foodList.addFood();
                break;

            case 2:
                cout << "Enter name of food to remove: ";
                getline(cin, foodName);
                foodList.removeFood(foodName);
                break;

            case 3:
                foodList.displayFoods();
                break;

            case 4:
                foodList.displayTotals();
                break;

            case 5:
                cout << "Enter food name to search: ";
                getline(cin, foodName);
                foodList.searchFood(foodName);
                break;

            case 6:
                foodList.sortFoods();
                cout << "Foods sorted alphabetically.\n";
                break;

            case 7:
                cout << "Enter filename to save to: ";
                getline(cin, filename);
                foodList.saveToFile(filename);
                break;

            case 8:
                cout << "Enter filename to load from: ";
                getline(cin, filename);
                foodList.loadFromFile(filename);
                break;

            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
