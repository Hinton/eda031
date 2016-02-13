#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

/** Finds primes in range [0,m] and stores in vector enums as C or P, returns largest prime within [0,m] */
int findPrimes(vector<char>& enums, int m) {
	int lastPrime = 0;

	/** Initial values */
	for (int i = 0; i < m; i++) {
		enums.push_back('P');
	}
	enums[0] = 'C';
	enums[1] = 'C';

	/** Find composites and mark them in enums */
	int upperBoundSquareRoot = (int)sqrt((double)m);
	bool *isComposite = new bool[m + 1];
	memset(isComposite, 0, sizeof(bool) * (m + 1));

	for (int i = 2; i <= upperBoundSquareRoot; i++) {
		if (!isComposite[i]) {
			for (int k = i * i; k <= m; k += i) {
				isComposite[k] = true;
				enums[k] = 'C';
			}
		}
	}

	/** Find largest prime in [0,m] */
	for (int i = upperBoundSquareRoot; i <= m; i++) {
		if (!isComposite[i]) {
			lastPrime = i;
		}
	}

	delete[] isComposite;

	return lastPrime;
}

int main() {
	int largestLimit = 100000;
	int printLimit = 200;
	vector<char> primeEnum;

	/** Sieve of Eratosthenes */
	int largestPrime = findPrimes(primeEnum, largestLimit);

	/** Print the primes in [0,printLimit] */
	cout << "*** Primes in the first " << printLimit << " numbers:" << endl;
	cout << "[";
	for (int i = 0; i < printLimit; i++) {
		if (primeEnum[i] == 'P') {
			if (i != printLimit - 1) {
				cout << i << " ";
			}
			else {
				cout << i;
			}
		}
	}
	cout << "]" << endl;

	/** Print the largest prime in [0,largestLimit] */
	cout << "\n*** The largest prime in the first 100,000 numbers:" << endl;
	cout << largestPrime << endl;
}