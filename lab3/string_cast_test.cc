#include <sstream>
#include <string>
#include <stdexcept>
#include "date.h"
#include <vector>

using namespace std;

template <typename T>
T string_cast(const string& a) {

	istringstream str(a);
	T object;

	str >> object;

	if (str.fail()) {
		throw invalid_argument(a);
	}

	return object;
}

int main() {
	try {
		int i = string_cast<int>("123");
		double d = string_cast<double>("12.34");
		Date date = string_cast<Date>("2015-01-10");

		// Check if values are correct.
		cout << i << "\n";
		cout << d << "\n";
		cout << date << "\n";
	}
	catch (invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
}