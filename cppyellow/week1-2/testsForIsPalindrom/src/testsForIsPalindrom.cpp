//============================================================================
// Name        : testsForIsPalindrom.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(string palindrom) {

    for (int i = 0; i < palindrom.size() / 2; ++i) {

        if (palindrom[i] != palindrom[palindrom.size() - i - 1]) {

            return false;
        }
    }

    return true;
}

void testEmptyString(){
	AssertEqual(IsPalindrom(""), true);
}

void testChar(){
	AssertEqual(IsPalindrom("1"), true);
}

void testPalindrom1(){
	AssertEqual(IsPalindrom("maxam"), true);
}

void testPalindrom2(){
	AssertEqual(IsPalindrom("level"), true);
}

void testPalindrom3(){
	AssertEqual(IsPalindrom("madam"), true);
}

void testPalindrom4(){
	AssertEqual(IsPalindrom("sadadsggdg"), false);
}

void testPalindrom5(){
	AssertEqual(IsPalindrom("asdadsadasdsadadasdadasdsss"), false);
}

void testPalindrom6(){
	AssertEqual(IsPalindrom("abba"), true);
}

void testPalindrom7(){
	AssertEqual(IsPalindrom("ad"), false);
}

void testPalindrom8(){
	AssertEqual(IsPalindrom("Aa"), false);
}

void testPalindrom9(){
	AssertEqual(IsPalindrom("sabba"), false);
}

void testPalindrom10(){
	AssertEqual(IsPalindrom(" madam"), false);
}

void testPalindrom11(){
	AssertEqual(IsPalindrom("m adam"), false);
}



int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(testEmptyString, "testEmptyString");
  runner.RunTest(testChar, "testChar");
  runner.RunTest(testPalindrom1, "testPalindrom1");
  runner.RunTest(testPalindrom2, "testPalindrom2");
  runner.RunTest(testPalindrom3, "testPalindrom3");
  runner.RunTest(testPalindrom4, "testPalindrom4");
  runner.RunTest(testPalindrom5, "testPalindrom5");
  runner.RunTest(testPalindrom6, "testPalindrom6");
  runner.RunTest(testPalindrom7, "testPalindrom7");
  runner.RunTest(testPalindrom8, "testPalindrom8");
  runner.RunTest(testPalindrom9, "testPalindrom9");
  runner.RunTest(testPalindrom10, "testPalindrom10");
  runner.RunTest(testPalindrom11, "testPalindrom11");



  return 0;
}
