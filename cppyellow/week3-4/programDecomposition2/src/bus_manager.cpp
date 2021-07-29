/*
 * bus_manager.cpp
 *
 *  Created on: 5 июл. 2020 г.
 *      Author: obozh
 */

#include "bus_manager.h"


void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
	  stops_for_buses[bus] = stops;
	  for (auto & item : stops)
	  {
		  buses_for_stops[item].push_back(bus);
	  }

  }

  BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
	  vector<string> buses;
	  if(buses_for_stops.count(stop) > 0)
		  buses = buses_for_stops.at(stop);
	  return {stop, buses};
  }

  StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

  AllBusesResponse BusManager::GetAllBuses() const {
    // Реализуйте этот метод
	  return {stops_for_buses};
  }



