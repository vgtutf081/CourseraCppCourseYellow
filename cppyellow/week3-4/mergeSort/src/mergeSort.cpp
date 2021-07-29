//============================================================================
// Name        : mergeSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <iterator>
#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if(range_end - range_begin < 2){
		return;
	}
	 vector<typename RandomIt::value_type> elements(range_begin, range_end);
	 auto it = begin(elements) + elements.size() / 2;
	 MergeSort(begin(elements), it);
	 MergeSort(it, end(elements));
	 merge(begin(elements), it, it, end(elements), range_begin);

}


int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
