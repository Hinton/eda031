#include <string>
#include <sstream>
#include "date.h"

using namespace std;

template <typename T> string toString(const T& a) {
	ostringstream ss;
	ss << a;
	return ss.str();
}

int main() {
	double d = 1.234;
	Date today;
	string sd = toString(d);
	string st = toString(today);

	cout << "Todays date: " << today << endl;
	cout << "Double: " << sd << endl;
	cout << "Date: " << st << endl;

	return 0;
}