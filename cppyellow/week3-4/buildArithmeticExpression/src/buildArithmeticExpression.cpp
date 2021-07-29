//============================================================================
// Name        : buildArithmeticExpression.cpp
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

	expression.push_back("(");
	expression.push_back(to_string(number));
	expression.push_back(") ");


	unsigned operations_count;
	cin >> operations_count;

	for (unsigned i = 0; i < operations_count; i++){
		string operation;
		cin >> operation;

		int other_number;
		cin >> other_number;

		expression.push_back(operation + " " + to_string(other_number));
		expression.push_back(") ");

		expression.push_front("(");
	}

	expression.pop_back();
	expression.pop_front();

	for (auto s : expression){
		cout << s;
	}

	return 0;
}
