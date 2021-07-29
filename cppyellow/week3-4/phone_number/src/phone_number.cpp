//============================================================================
// Name        : phone_number.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "phone_number.h"
#include <sstream>
using namespace std;

PhoneNumber::PhoneNumber(const string &international_number){

	stringstream stream(international_number);
	string country_code, city_code, local_number;

	if(stream.eof()){
		throw invalid_argument("");
	}
	else{
        getline(stream, country_code, '-');
        getline(stream, city_code, '-');
        getline(stream, local_number, '\n');
	}

	if(country_code[0] != '+'){
		throw invalid_argument("");
	}
	else{
		for (unsigned i = 1; i < country_code.size(); i++){
			country_code_ += country_code[i];
		}
	}

	if (city_code.empty()){
		throw invalid_argument("");
	}
	else{
		city_code_ = city_code;
	}

	if (local_number.empty()){
		throw invalid_argument("");
	}
	else{
		local_number_ = local_number;
	}
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_+ "-" + city_code_ + "-" + local_number_;
}


