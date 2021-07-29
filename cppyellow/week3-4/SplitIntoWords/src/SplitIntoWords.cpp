//============================================================================
// Name        : SplitIntoWords.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<string> SplitIntoWords(const string& s){

	vector<string> result;

	if(find(begin(s), end(s), ' ') == end(s)){
		return {s};
	}

	for (auto it2 = find(begin(s), end(s), ' '),it1 = begin(s); it2 != end(s);){
		result.push_back({it1, it2});
		it1 = ++it2;
		it2 = find(it1, end(s), ' ');
		if (it2 == end(s)){
			result.push_back({it1, it2});
			break;
		}
	}

	return result;
}


