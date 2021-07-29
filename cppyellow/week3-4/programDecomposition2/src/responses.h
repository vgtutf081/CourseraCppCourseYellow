#pragma once

#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

struct BusesForStopResponse {
	string stop;
	vector <string> buses;
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  // Наполните полями эту структуру
	string bus;
	vector <string> stops;
	map <string, vector<string>> BusesForStop;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  // Наполните полями эту структуру
	map <string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
