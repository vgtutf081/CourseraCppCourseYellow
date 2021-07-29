//============================================================================
// Name        : buildArithmeticExpressionPart2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
#include <deque>

int main() {

	deque<string> expression;

	int number;
	cin >> number;


	expression.push_back(to_string(number));
	expression.push_back(" ");

	unsigned operations_count;
	cin >> operations_count;

	string last_operation;

	for (unsigned i = 0; i < operations_count; i++){
		string operation;
		cin >> operation;

		int other_number;
		cin >> other_number;

		if ((last_operation == "+" || last_operation == "-") && (operation == "*" || operation == "/")){
			expression.pop_back();
			expression.push_back(") ");
			expression.push_front("(");
		}

		expression.push_back(operation + " " + to_string(other_number));
		expression.push_back(" ");

		last_operation = operation;
	}

	expression.pop_back();

	for (auto s : expression){
		cout << s;
	}

	return 0;
}
