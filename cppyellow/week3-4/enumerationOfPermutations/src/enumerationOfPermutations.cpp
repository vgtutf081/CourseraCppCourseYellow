//============================================================================
// Name        : enumerationOfPermutations.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


int main() {

    int number;
    cin >> number;
    vector<int> numbers(number);
    for (int i = 0; i < number; ++i) {
    	numbers[i] = i + 1;
    }

     vector<vector<int>> output;
     do {
         output.push_back({begin(numbers), end(numbers)});
     }
     while(next_permutation(begin(numbers), end(numbers)));

     reverse(begin(output), end(output));

     for (auto& vector : output) {
         for (auto& i : vector) {
             cout << i << " ";
         }
         cout << endl;
     }



	return 0;
}
