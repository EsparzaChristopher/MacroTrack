#ifndef FOOD_H
#define FOOD_H

#include <string>   // Use this for std::string
using namespace std;
 // Node structure for each food item
 struct FoodNode {
    string foodName;
    float protein;
    float carbs;
    float fat;
    FoodNode* next;
};
// Class declaration for the food list
class food {
public:
    // Public member functions
    void addFood();
    void removeFood(string name);
    void displayFoods();
    void displayTotals();
    FoodNode* searchFood(string name);
    void sortFoods();
    void saveToFile(string filename);
    void loadFromFile(string filename);
    ~food();  // Destructor

private:
   

    FoodNode* head = nullptr; // Pointer to the start of the list
};

#endif // FOOD_H
