//============================================================================
// Name        : FindGreaterElements.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <algorithm>

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){

	vector<T> GreaterElements;

	for (auto it = begin(elements); it != end(elements); ){
		if (*it > border){
			GreaterElements.push_back(*it);
		}
		++it;
	}

	sort(GreaterElements.begin(),GreaterElements.end());

	return GreaterElements;

}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}

