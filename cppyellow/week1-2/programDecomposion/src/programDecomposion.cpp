//============================================================================
// Name        : programDecomposion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
	string request;
	is >> request;
	if (request == "NEW_BUS"){

		is >> q.bus;

		int stop_count;
		is >> stop_count;

		q.stops.resize(stop_count);
		for (string& stop : q.stops) {
			is >> stop;
		}
		q.type = QueryType::NewBus;

	}
	else if (request == "BUSES_FOR_STOP"){
		is >> q.stop;
		q.type = QueryType::BusesForStop;
	}
	else if (request == "STOPS_FOR_BUS"){
		is >> q.bus;
		q.type = QueryType::StopsForBus;
	}
	else if (request == "ALL_BUSES"){
		q.type = QueryType::AllBuses;
	}

  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
	string stop;
	vector <string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию

	if (r.stop.empty() || r.buses.empty()) {
		os << "No stop";
	} else {
	     for (const string& bus : r.buses) {
	    	 os << bus << " ";
	     }
	     }
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
	string bus;
	vector <string> stops;
	map <string, vector<string>> BusesForStop;

};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
	 if (r.bus.empty() || r.stops.empty()) {
		 os << "No bus";
	 }
	 else{
		for (const string& stop : r.stops) {
			os << "Stop " << stop << ": ";
		    if (r.BusesForStop.at(stop).size() == 1) {
		    	os << "no interchange" << endl;
		        }
		    else {
		        for (const string& other_bus : r.BusesForStop.at(stop)) {
		            if (r.bus != other_bus) {
		            	os << other_bus << " ";
		            }
		         }
		     }
		 }os << endl;
	 }
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
	map <string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
		if (r.buses.empty()) {
			os << "No buses";
	    } else {
	        for (const auto& bus_item : r.buses) {
	           os << "Bus " << bus_item.first << ": ";
	           for (const string& stop : bus_item.second) {
	           os << stop << " ";
	           }
	           os << endl;
	        }
	      }

  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
	  stops_for_buses[bus] = stops;
	  for (auto & item : stops)
	  {
		  buses_for_stops[item].push_back(bus);
	  }

  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
	  vector<string> buses;
	  if(buses_for_stops.count(stop) > 0)
		  buses = buses_for_stops.at(stop);
	  return {stop, buses};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
	  vector<string> stops;
	  if(stops_for_buses.count(bus) > 0)
		  stops = stops_for_buses.at(bus);

	  map <string, vector<string>> BusesForStop;

	  for (auto & item : stops){
		  BusesForStop[item] = buses_for_stops.at(item);
	  }
	  return {bus, stops, BusesForStop};
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
	  return {stops_for_buses};
  }

private:
    map<string, vector<string>> buses_for_stops;
    map<string, vector<string>> stops_for_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
