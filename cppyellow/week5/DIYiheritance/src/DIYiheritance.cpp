//============================================================================
// Name        : DIYiheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
public:
	Animal(const string & n = "animal") :
	 Name(n){}

    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& name = "dog") : Animal(name) {}
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {

	return 0;
}
