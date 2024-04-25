// menusystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedListMenu.h"
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedListMenu menu;
    
    string* ingredientsPtr1 = new string[3];
    ingredientsPtr1[0] = "Ingredient1";
    ingredientsPtr1[1] = "Ingredient2";
    ingredientsPtr1[2] = "Ingredient3";
    MenuItem item1(101, "Cheeseburger", 5.99, 'o', 'M', ingredientsPtr1, 3);
    menu.insertByPrice(item1);
    cout << menu.getSize() << endl;

    cout << menu << endl;

    string* ingredientsPtr2 = new string[3];
    ingredientsPtr2[0] = "Ingredient1";
    ingredientsPtr2[1] = "Ingredient2";
    ingredientsPtr2[2] = "Ingredient3";

    MenuItem item2(102, "Hamburger", 2.99, 'O', 'M', ingredientsPtr2, 3);

    
    menu.insertByPrice(item2);

    cout << menu.getSize() << endl;
    cout << "HIIIIIIIIIIIIIIIIIIII" << endl;

    
}


