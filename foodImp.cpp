#include "food.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Adds a new food item to the end of the linked list
void food::addFood() {
    string name;
    float proteins, carbss, fats;

    // Get user input
    cout << "Enter food name: ";
    getline(cin, name);
    cout << "Enter protein (g): ";
    cin >> proteins;
    cout << "Enter carbohydrates (g): ";
    cin >> carbss;
    cout << "Enter fat (g): ";
    cin >> fats;
    cin.ignore();  // Clear newline character from input buffer

    // Create new node with input data
    FoodNode* newNode = new FoodNode{name, proteins, carbss, fats, nullptr};

    // If list is empty, set head to new node
    if (head == nullptr) {
        head = newNode;
    } else {
        // Otherwise, append to end of list
        FoodNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Food item added successfully!\n";
}

// Removes a food item from the list by name
void food::removeFood(string name) {
    FoodNode* current = head;
    FoodNode* previous = nullptr;

    // Traverse the list to find the node to remove
    while (current != nullptr && current->foodName != name) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        // Food not found
        cout << "Food item not found.\n";
    } else {
        // Remove node from list
        if (previous) {
            previous->next = current->next;
        } else {
            head = current->next;  // If head is being removed
        }
        delete current;
        cout << name << " has been removed.\n";
    }
}

// Displays all food items in the list
void food::displayFoods() {
    FoodNode* list = head;
    while (list != nullptr) {
        cout << "Name: " << list->foodName;
        cout << "\nProtein: " << list->protein;
        cout << "\nCarbohydrates: " << list->carbs;
        cout << "\nFat: " << list->fat;
        cout << "\n-------------------------------\n";
        list = list->next;
    }
}

// Calculates and displays total macros from all foods
void food::displayTotals() {
    float totprot = 0, totcarb = 0, totfat = 0;
    FoodNode* list = head;

    while (list != nullptr) {
        totprot += list->protein;
        totcarb += list->carbs;
        totfat += list->fat;
        list = list->next;
    }

    cout << "Total Protein: " << totprot;
    cout << "\nTotal Carbohydrates: " << totcarb;
    cout << "\nTotal Fat: " << totfat << "\n";
}

// Searches for a food by name and returns the node (or nullptr if not found)
FoodNode* food::searchFood(string name) {
    FoodNode* search = head;
    while (search != nullptr && search->foodName != name) {
        search = search->next;
    }

    if (search == nullptr) {
        cout << "There is no food by that name!\n";
    }
    return search;
}

// Sorts the list alphabetically by food name using a bubble sort
void food::sortFoods() {
    if (!head || !head->next) return;  // No need to sort if 0 or 1 item

    bool swapped;
    do {
        swapped = false;
        FoodNode* current = head;
        FoodNode* prev = nullptr;

        while (current && current->next) {
            FoodNode* nextNode = current->next;

            // Compare food names lexicographically
            if (current->foodName > nextNode->foodName) {
                // Swap current and nextNode
                if (prev) {
                    prev->next = nextNode;
                } else {
                    head = nextNode;
                }
                current->next = nextNode->next;
                nextNode->next = current;
                swapped = true;

                // Move prev forward
                prev = nextNode;
            } else {
                // Move to next pair
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

// Saves the food list to a text file
void food::saveToFile(string filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Failed to open file for writing: " << filename << endl;
        return;
    }

    FoodNode* current = head;
    while (current) {
        // Save as: name protein carbs fat
        outFile << current->foodName << " "
                << current->protein << " "
                << current->carbs << " "
                << current->fat << "\n";
        current = current->next;  // Advance to next node
    }

    outFile.close();
    cout << "Food list saved to " << filename << endl;
}

// Loads the food list from a file, replacing any existing list
void food::loadFromFile(string filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Failed to open file for accessing: " << filename << endl;
        return;
    }

    // Clear the current list
    FoodNode* current = head;
    while (current) {
        FoodNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    // Read new data
    string line, foodname;
    float proteins, carbss, fats;

    while (getline(inFile, line)) {
        istringstream ss(line);
        ss >> foodname >> proteins >> carbss >> fats;

        FoodNode* newNode = new FoodNode{foodname, proteins, carbss, fats, nullptr};

        if (!head) {
            head = newNode;
        } else {
            FoodNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    inFile.close();
    cout << "Food list loaded from " << filename << endl;
}

// Destructor: Cleans up all nodes in the list to prevent memory leaks
food::~food() {
    FoodNode* current = head;
    while (current) {
        FoodNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;  // Final safety cleanup
}
