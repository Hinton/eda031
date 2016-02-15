#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

/** Finds primes in range [0,m] and stores in vector enums as C or P, returns largest prime within [0,m] */
int findPrimes(string &enums, int m) {
	int lastPrime = 0;

	// Setup start
	enums.replace(0, 2, "CC");

	/** Find composites and mark them in enums */
	int upperBoundSquareRoot = sqrt(m);

	for (int i = 2; i <= upperBoundSquareRoot; i++) {
		if (enums.at(i) == 'P') {
			for (int k = i * i; k <= m; k += i) {
				enums.replace(k, 1, "C");
			}
		}
	}

	/** Find largest prime in [0,m] */
	for (int i = upperBoundSquareRoot; i <= m; i++) {
		if (enums.at(i) == 'P') {
			lastPrime = i;
		}
	}

	return lastPrime;
}

int main() {
	int largestLimit = 100000;
	int printLimit = 200;

	/** Sieve of Eratosthenes */
	string primeEnum(largestLimit, 'P');
	int largestPrime = findPrimes(primeEnum, largestLimit);

	/** Print the primes in [0,printLimit] */
	cout << "*** Primes in the first " << printLimit << " numbers:" << endl;
	cout << "[";
	
	for (string::iterator it = primeEnum.begin(); it != primeEnum.end(); ++it)
	{
		int index = std::distance(primeEnum.begin(), it);
		
		if (index > printLimit) {
			break;
		}

		if (*it == 'P') {
			cout << index << ' ';
		}
	}
	cout << "]" << endl;

	/** Print the largest prime in [0,largestLimit] */
	cout << "\n*** The largest prime in the first 100,000 numbers:" << endl;
	cout << largestPrime << endl;
}