//============================================================================
// Name        : GetRefStrict.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <map>


template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
    try {
        return m.at(k);
    } catch (const out_of_range & oor) {
        throw runtime_error("Out of Range");
    }
}

int main (){

map<int, string> m = {{0, "value"}};
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl; // выведет newvalue
}
