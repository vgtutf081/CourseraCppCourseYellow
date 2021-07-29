//============================================================================
// Name        : setOfFigures.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <istream>
#include <memory>
#include <sstream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct Figure{
public:
	virtual string Name () = 0;
	virtual float Perimeter () = 0;
	virtual float Area () = 0;
};

class Circle : public Figure{
public:
	Circle(int r)
	:_r(r){}
	string Name () override {
		return "CIRCLE";
	}
	float Perimeter() override {
		return _r*2*3.14;
	}
	float Area () override {
		return _r*_r*3.14;
	}

private:
	const float _r;

};

class Rect : public Figure{
public:
	Rect(int a, int b)
	:_a(a), _b(b){}
	string Name () override {
		return "RECT";
	}
	float Perimeter() override {
		return 2*(_a+_b);
	}
	float Area () override {
		return _a*_b;
	}

private:
	const float _a,_b;
};

class Triangle : public Figure{
public:
	Triangle(int a, int b, int c)
	:_a(a), _b(b), _c(c) {}
	string Name () override {
		return "TRIANGLE";
	}
	float Perimeter() override {
		return (_a+_b+_c);
	}
	float Area () override {
		float semiP = (_a+_b+_c)/2;
		return sqrt(semiP*(semiP -_a)*(semiP -_b)*(semiP -_c));
	}

private:
	const float _a, _b, _c;
};
shared_ptr<Figure> CreateFigure(istringstream & stream){
	string name;
	stream >> name;

	if(name == "CIRCLE"){
		int radius;
		stream >> radius;

		return make_shared<Circle>(radius);
	}
	else if(name == "RECT"){
		int sideA, sideB;
		stream >> sideA >> sideB;

		return make_shared<Rect>(sideA, sideB);
	}
	else if(name == "TRIANGLE"){
		int sideA, sideB, sideC;
		stream >> sideA >> sideB >> sideC;

		return make_shared<Triangle>(sideA, sideB, sideC);
	}
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
