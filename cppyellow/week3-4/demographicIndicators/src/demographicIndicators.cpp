//============================================================================
// Name        : demographicIndicators.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <iterator>
#include <algorithm>


enum class Gender {
  FEMALE,
  MALE
};


struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};


// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons){

	cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;

	auto females_it = partition(begin(persons), end(persons), [](const Person& person)
			{return person.gender == Gender::FEMALE;});
	cout  << "Median age for females = " << ComputeMedianAge(begin(persons), females_it) << endl;

	cout  << "Median age for males = " << ComputeMedianAge(females_it, end(persons)) << endl;

	auto employed_females_it = partition(begin(persons), females_it, [](const Person& person)
			{return person.is_employed == true;});
	cout  << "Median age for employed females = " << ComputeMedianAge(begin(persons), employed_females_it) << endl;

	cout  << "Median age for unemployed females = " << ComputeMedianAge(employed_females_it, females_it) << endl;

	auto employed_males_it = partition(females_it, end(persons), [](const Person& person)
			{return person.is_employed == true;});
	cout  << "Median age for employed males = " << ComputeMedianAge(females_it, employed_males_it) << endl;

	cout  << "Median age for unemployed males = " << ComputeMedianAge(employed_males_it, end(persons)) << endl;

}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
