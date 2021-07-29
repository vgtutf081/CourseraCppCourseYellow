//============================================================================
// Name        : AllSqr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <utility>

template <typename First, typename Second> pair <First, Second> operator * (const pair <First, Second> & p1, const pair <First, Second> & p2);
template <typename vect> vector <vect> operator * (const vector <vect> & v1, const vector <vect> & v2);
template <typename Key, typename Value> map <Key, Value> operator * (const map <Key, Value> & m1, const map <Key, Value> & m2);
template <typename T> T Sqr(T x);

template <typename First, typename Second>
pair <First, Second> operator * (const pair <First, Second> & p1, const pair <First, Second> & p2){

	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;

	return make_pair(f, s);
}

template <typename vect>
vector <vect> operator * (const vector <vect> & v1, const vector <vect> & v2){

	vector<vect> result;

	for (unsigned i = 0; i < v1.size(); i++)
	{
		result.push_back(v1[i] * v2[i]);
	}

	return result;
}

template <typename Key, typename Value>
map <Key, Value> operator * (const map <Key, Value> & m1, const map <Key, Value> & m2){

	map <Key, Value> result;

	for (auto item : m1)
	{
		auto value2 = m2.at(item.first);
		result[item.first] = item.second * value2;
	}

	return result;
}

template <typename T>
T Sqr(T x){

	return x * x;
}

int main()
{
// Пример вызова функции
vector<int> v = {1, 2, 3};
cout << "vector:";
for (int x : Sqr(v)) {
  cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
cout << "map of pairs:" << endl;
for (const auto& x : Sqr(map_of_pairs)) {
  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
}
return 0;
}

