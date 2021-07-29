//============================================================================
// Name        : mergeSortPart2.cpp
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
	if(range_end - range_begin < 3){
		return;
	}
	 vector<typename RandomIt::value_type> range(range_begin, range_end);
	 auto it1 = begin(range) + range.size() / 3;
	 auto it2 = it1 + range.size() / 3;

	 MergeSort(begin(range), it1);
	 MergeSort(it1, it2);
	 MergeSort(it2, end(range));

	 vector<typename RandomIt::value_type> elements;

	 merge(begin(range),it1, it1, it2, back_inserter(elements));

	 merge(begin(elements), end(elements), it2, end(range), range_begin);

}



