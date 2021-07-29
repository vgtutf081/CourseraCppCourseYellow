//============================================================================
// Name        : partOfVector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void PrintVectorPart(const vector<int>& numbers){

	auto result = find_if(begin(numbers), end(numbers),[](const int& num) {
		return num < 0;
	});

	while (result != begin(numbers)){
		--result;
		cout << *result << " ";
	}

}

int main() {

	PrintVectorPart({6, 1, 8, -5, 4});
	  cout << endl;
	  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	  cout << endl;
	  PrintVectorPart({6, 1, 8, 5, 4});
	  cout << endl;

	return 0;
}
