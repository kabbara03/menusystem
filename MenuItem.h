#ifndef MENU_ITEM
#define MENU_ITEM

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private:
    int id;
    string name;
    double price; 
    char type; // 'V' for vegan, 'G' for vegetarian, 'N' for normal
    char category; // 'A' for Appetizers, 'M' for Main Dishes, 'D' for Desserts, 'B' for Beverages
    char** ingredientsPtr; // Pointer to an array of strings conatining ingredients  
    int ingredientsSize; // Size of the ingredients array

public:
    // Constructor
    MenuItem(int Id, string Name, double Price, char Type, char Category,  string* ingredientsPtr, int size);
    MenuItem();
    // Destructor
    ~MenuItem();

    // Getter methods
    int getId() const;
    string getName() const;
    double getPrice() const;
    char getType() const;
    char getCategory() const;
    char** getIngredientsPtr() const;
    int getIngredientsSize() const;

    // Setter methods
    void setId(int Id);
    void setName(const string& Name);
    void setPrice(double Price);
    void setType(char Type);
    void setCategory(char Category);
    void setIngredientsPtr( string* Ingredients, int size);
    

    // Method to display menu item details
    void display(ostream& out) const;

};

ostream& operator<<(ostream& out, const MenuItem& m);

#endif
