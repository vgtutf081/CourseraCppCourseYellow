/*
 * responses.cpp
 *
 *  Created on: 5 ���. 2020 �.
 *      Author: obozh
 */

#include "responses.h"




ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.stop.empty() || r.buses.empty()) {
		os << "No stop";
	} else {
	     for (const string& bus : r.buses) {
	    	 os << bus << " ";
	     }
	     }
  return os;
}


ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // ���������� ��� �������
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
  return os;
}



ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // ���������� ��� �������
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
