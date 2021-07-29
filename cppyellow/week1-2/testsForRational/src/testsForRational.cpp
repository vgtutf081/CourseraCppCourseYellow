//============================================================================
// Name        : testsForRational.cpp
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

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
    	new_numerator = 0;
    	new_denominator = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
    	bool isNegative = false;

    	if (denominator == 0)
    	{
    		throw invalid_argument("Invalid argument");
    	}

    	if (numerator == 0)
    	{
    		new_numerator = 0;
			new_denominator = 1;
    	}
    	else
		{
    		if (numerator < 0 || denominator < 0)
    		{
    		if(numerator < 0 && denominator < 0)
    		{
    			isNegative = false;
    		}
    		else
    		{
    			isNegative = true;
    		}
    		}

    		numerator = abs(numerator);
			denominator = abs(denominator);

			new_numerator = numerator;
			new_denominator = denominator;



			while (numerator != 0 && denominator != 0)
			    if (numerator > denominator)
			    	numerator = numerator % denominator;
			    else
				denominator = denominator % numerator;

			new_numerator /= numerator + denominator;
			new_denominator /= numerator + denominator;

			if(isNegative)
				new_numerator *= -1;

		}

    }

    int Numerator() const {
    	return new_numerator;
        // Реализуйте этот метод
    }

    int Denominator() const {
    	return new_denominator;
        // Реализуйте этот метод
    }

    void setNumerator (int newnumerator)
	{
    	new_numerator = newnumerator;
	}

    void setDenominator (int newdenominator)
    	{
    	new_denominator = newdenominator;
    	}

private:

    int new_numerator;
    int new_denominator;
    // Добавьте поля
};

int fractionfactor (int commonDenominator, int Denominator)
{
	return commonDenominator/Denominator;
}


int commonDenominator (int lhsDen, int rhsDen)
{
	int temp = 0;

	if (lhsDen == rhsDen)
	return lhsDen;
	else if (lhsDen > rhsDen)
	{
		if(lhsDen % rhsDen == 0)
		return lhsDen;
		else
		{
			int i = 2;
			do
			{
				temp = lhsDen * i;
				i++;
			}
			while (!(temp % rhsDen == 0));
			return temp;
		}
	}
	else
	{
	if(rhsDen % lhsDen == 0)
		return rhsDen;
		else
		{
			int i = 2;
			do
			{
				temp = rhsDen * i;
				i++;
			}
				while (!(temp % lhsDen == 0));
				return temp;
			}
	}


}

bool operator == (Rational lhs, Rational rhs) {

			int frictionfactorlhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), lhs.Denominator());
			int frictionfactorrhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), rhs.Denominator());


				return (lhs.Numerator() * frictionfactorlhs == rhs.Numerator() * frictionfactorrhs);
}

Rational operator + (Rational lhs, Rational rhs)
		{
				int frictionfactorlhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), lhs.Denominator());
				int frictionfactorrhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), rhs.Denominator());

			return {(lhs.Numerator() * frictionfactorlhs) + (rhs.Numerator() * frictionfactorrhs), commonDenominator(lhs.Denominator(), rhs.Denominator())};
		}

Rational operator - (Rational lhs, Rational rhs)
		{
					int frictionfactorlhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), lhs.Denominator());
					int frictionfactorrhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), rhs.Denominator());

				return {(lhs.Numerator() * frictionfactorlhs) - (rhs.Numerator() * frictionfactorrhs), commonDenominator(lhs.Denominator(), rhs.Denominator())};
		}

Rational operator / (Rational lhs, Rational rhs)
		{

			if(rhs.Numerator() * lhs.Denominator() == 0)
			{
				throw domain_error("Division by zero");
			}

		return {lhs.Numerator() * rhs.Denominator(), rhs.Numerator() * lhs.Denominator()};

		}

Rational operator * (Rational lhs, Rational rhs)
		{

		return {lhs.Numerator() * rhs.Numerator(), rhs.Denominator() * lhs.Denominator()};

		}

ostream& operator << (ostream & stream,const Rational & rational)
{
	stream << rational.Numerator() << '/' << rational.Denominator();
	return stream;
}

istream& operator >> (istream & stream, Rational & rational)
{
	int numerator = rational.Numerator();
	int denominator = rational.Denominator();

	stream >> numerator;
	stream.ignore(1);
	stream >> denominator;

	Rational temp{numerator,denominator};

	rational.setNumerator(temp.Numerator());
	rational.setDenominator(temp.Denominator());


	return stream;

}

bool operator < (const Rational & lhs,const Rational & rhs)
{
	int frictionfactorlhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), lhs.Denominator());
	int frictionfactorrhs = fractionfactor(commonDenominator(lhs.Denominator(), rhs.Denominator()), rhs.Denominator());



	return (lhs.Numerator() * frictionfactorlhs ) < (rhs.Numerator() * frictionfactorrhs );
}


void testDefaultConstructor (){

	Rational r;
	AssertEqual(r.Numerator(), 0);
	AssertEqual(r.Denominator(), 1);
}

void testFractionReduction (){
	Rational r(5,10);
	AssertEqual(r.Numerator(), 1);
	AssertEqual(r.Denominator(), 2);
}

void testNegativefraction (){
	Rational r(-5,10);
	AssertEqual(r.Numerator(), -1);
	AssertEqual(r.Denominator(), 2);
	Rational d(5,-10);
	AssertEqual(d.Numerator(), -1);
	AssertEqual(d.Denominator(), 2);
}

void testPositivefraction (){
	Rational r(-5,-10);
	AssertEqual(r.Numerator(), 1);
	AssertEqual(r.Denominator(), 2);
}

void testZeroNumerator (){
	Rational r(0,10);
	AssertEqual(r.Numerator(), 0);
	AssertEqual(r.Denominator(), 1);
}


int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(testDefaultConstructor, "testDefaultConstructor");
  runner.RunTest(testFractionReduction, "testFractionReduction");
  runner.RunTest(testNegativefraction, "testNegativefraction");
  runner.RunTest(testPositivefraction, "testPositivefraction");
  runner.RunTest(testZeroNumerator, "testZeroNumerator");


  return 0;
}
