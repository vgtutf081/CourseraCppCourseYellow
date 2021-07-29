//============================================================================
// Name        : sum_reverse_sort_header.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "sum_reverse_sort.h"
#include <algorithm>


int Sum(int x, int y){
	return x + y;
}
string Reverse(string s){
    string tmp = "";
    for (size_t d = s.length(); d > 0; --d) {
        size_t i = d - 1;
        tmp += s[i];
    }
    return tmp;
}
void Sort(vector<int>& nums){
	sort(nums.begin(), nums.end());
}

