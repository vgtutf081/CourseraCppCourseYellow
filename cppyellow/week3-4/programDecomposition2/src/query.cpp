/*
 * query.cpp
 *
 *  Created on: 5 июл. 2020 г.
 *      Author: obozh
 */


#include "query.h"

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


