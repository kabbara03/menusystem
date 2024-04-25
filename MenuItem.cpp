#include "MenuItem.h"

MenuItem::MenuItem(int Id, string Name, double Price, char Type, char Category,  string* Ingredients, int size) {
    
    // Set attributes using setters to perform validation
    setId(Id);
    setName(Name);
    setPrice(Price);
    setType(Type);
    setCategory(Category);
    setIngredientsPtr(Ingredients, size);
}

MenuItem::MenuItem() {
	id = 0;
	name = "";
	price = 10;
	type = '\0';
	category = '\0';
    ingredientsPtr = NULL;
	ingredientsSize = 0;
}

MenuItem::~MenuItem() {
    delete[] ingredientsPtr;
}

int MenuItem::getId() const {
    return id;
}

string MenuItem::getName() const {
    return name;
}

double MenuItem::getPrice() const {
    return price;
}

char MenuItem::getType() const {
    return type;
}

char MenuItem::getCategory() const {
    return category;
}

char** MenuItem::getIngredientsPtr() const {
    return ingredientsPtr;
}

int MenuItem::getIngredientsSize() const {
    return ingredientsSize;
}

void MenuItem::setId(int id) {
    if (id >= 100 && id <= 499) {
        this->id = id;
    }
    else
        this->id = 0;
}

void MenuItem::setName(const string& name) {
    if (!name.empty()) {
        this->name = name;
    }
    else
        this->name = "";
}

void MenuItem::setPrice(double price) {
    if (price >= 0.0) {
        this->price = price;
    }
    else
        this->price = 10;
}

void MenuItem::setType(char type) {
    type = toupper(type);

    if (type == 'V' || type == 'G' || type == 'O') {
        this->type = type;
    }
    else
        this->type = '\0';
}

void MenuItem::setCategory(char category) {
    category = toupper(category);

    if (category == 'A' || category == 'M' || category == 'D' || category == 'B') {
        this->category = category;
    }
    else
        this->category = '\0';
}

void MenuItem::setIngredientsPtr(string* ingredientsPtr1, int size)
{
    
    if (size > 0 ) {
        for (int i = 0; i < ingredientsSize; ++i) {
            delete[] ingredientsPtr[i];
        }
        delete[] ingredientsPtr;

        // Allocate memory for new array
        ingredientsPtr = new char* [size];

        // Copy strings from source array to ingredients array
        for (int i = 0; i < size; ++i) {
            // Convert std::string to C-style string and copy contents

            ingredientsPtr[i] = new char[ingredientsPtr1[i].length() + 1]; // +1 for null terminator

            strcpy(ingredientsPtr[i], ingredientsPtr1[i].c_str());
        }

        // Update ingredientsSize
        ingredientsSize = size;
    }
    else {
        ingredientsSize = 0;
        ingredientsPtr = NULL; 
    }

}

ostream& operator<<(ostream& out, const MenuItem& m) {
    m.display(out);
    return out;
}

void MenuItem::display(ostream& out) const {
    out << name << ", " << type << " " << category << " "
    << "$" << price << " ";
    out << ingredientsPtr << endl;
    
    for (int i = 0; i < ingredientsSize; ++i)
    {
        out << "before ingredient" << endl;
        out << ingredientsPtr[i];
        if (i < ingredientsSize - 1) 
        {
            out << ", ";
        }
    }
    
}

