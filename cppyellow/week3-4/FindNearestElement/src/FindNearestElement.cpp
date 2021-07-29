//============================================================================
// Name        : FindNearestElement.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border){

	if (numbers.size() == 0){
		return end(numbers);
	}

	auto it = find(begin(numbers), end(numbers), border);

		for (int i = 0;it == end(numbers); i++){

			(i % 2 == 0) ? border += i : border -=i;

			it = find(begin(numbers), end(numbers), border);
			}
		return it;

};


// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
