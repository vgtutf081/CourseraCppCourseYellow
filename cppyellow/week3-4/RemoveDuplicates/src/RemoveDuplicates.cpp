//============================================================================
// Name        : RemoveDuplicates.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


template <typename T>
void RemoveDuplicates(vector<T>& elements)
{
	sort(begin(elements), end(elements));
	auto it = unique(begin(elements), end(elements));
	elements.erase(it, end(elements));
}

