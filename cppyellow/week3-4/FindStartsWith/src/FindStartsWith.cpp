//============================================================================
// Name        : FindStartsWith.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix){

	string border1 = {prefix};
    auto first = lower_bound(range_begin, range_end, border1);

    auto next_char = static_cast<char>(prefix + 1);
    string border2 = {next_char};
    auto second = upper_bound(range_begin, range_end, border2);

    return std::make_pair(first, second);
}


