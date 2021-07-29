//============================================================================
// Name        : refactoring.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
	Human(const string name, const string role) : Name(name), Role(role) {}

	string getName() const{
		return Name;
	}

	string getRole() const{
		return Role;
	}

	virtual void Walk(const string & destination) const = 0;

private:
	const string Name;
	const string Role;
};


class Student : public Human {
public:
    Student(const string & name,const string & favouriteSong)
	: Human(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << " "<< getRole() << ": " << getName() << " learns" << endl;
    }

    void Walk(const string & destination) const override  {
        cout << " "<< getRole() << ": " << getName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << " "<< getRole() << ": " << getName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const string & name,const string & subject)
	: Human(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << " "<< getRole() << ": " << getName() << " teaches: " << Subject << endl;
    }

    void Walk(const string & destination) const override {
        cout << " "<< getRole() << ": " << getName() << " walks to: " << destination << endl;
    }

private:
    const string Subject;
};


class Policeman : public Human {
public:
    Policeman(string name) : Human(name, "Policeman") {}

    void Check(Human & h) const {
        cout << " "<< getRole() << ": " << getName() << " checks " << h.getName()
        << ". " << h.getRole() <<"'s name is: " << h.getName() << endl;
    }

    void Walk(const string & destination) const override {
        cout << " "<< getRole() << ": " << getName() << " walks to: " << destination << endl;
    }
};


void VisitPlaces(Human & h, vector<string> places){
    for (const auto & p : places) {
        h.Walk(p);
    }
}



int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
