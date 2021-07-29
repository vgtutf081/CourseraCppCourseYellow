//============================================================================
// Name        : WeightOfBlocks.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>


int main() {


	uint64_t BlocksQuanity;
	uint64_t BlocksDensity;

	cin >> BlocksQuanity;
	cin >> BlocksDensity;

	vector <vector <uint64_t>> WHD (BlocksQuanity);

	for (unsigned i = 0; i < BlocksQuanity; i++)
	{
		for (unsigned j = 0; j < 3; j++)
		{
			uint64_t sideLength;
		cin >> sideLength;
		WHD[i].push_back(sideLength);
		}
	}

	uint64_t value = 0;

	for (unsigned i = 0; i < BlocksQuanity; i++)
	{
		value += WHD[i][0] * WHD[i][1] * WHD[i][2];
	}

	uint64_t a = value * BlocksDensity;

	cout << a;

	max(string ("abc"), string("qwe"));

	return 0;
}
