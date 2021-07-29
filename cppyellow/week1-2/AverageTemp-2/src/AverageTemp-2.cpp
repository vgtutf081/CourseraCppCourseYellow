//============================================================================
// Name        : AverageTemp-2.cpp
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

	int64_t days;
	cin >> days;

	if(days == 0)
	{
		return 0;
	}

	vector <int64_t> temps;
	int64_t sum = 0;

	for (int64_t i = 0; i < days; i++)
	{
		int64_t temp;
		cin >> temp;
		temps.push_back(temp);
		sum += temp;
	}

	cout << count_if(begin(temps), end(temps), [days,sum](int64_t x) {
	if (x > sum/days) {
	return true;
	}
	return false;
	});

	cout << endl;

	for (int64_t i = 0; i < days; i++)
	{
		if(temps[i] > (sum/days))
		{
			cout << i << " ";
		}
	}

	return 0;
}
