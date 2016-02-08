#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

vector<int> findPrimes(int m) {
	vector<int> primes;
	int upperBoundSquareRoot = (int)sqrt((double)m);
	bool *isComposite = new bool[m + 1];
	memset(isComposite, 0, sizeof(bool) * (m + 1));
	for (int i = 2; i <= upperBoundSquareRoot; i++) {
		if (!isComposite[i]) {
			primes.push_back(i);
			for (int k = i * i; k <= m; k += i)
				isComposite[k] = true;
		}
	}
	for (int i = upperBoundSquareRoot; i <= m; i++)
		if (!isComposite[i])
			primes.push_back(i);
	delete[] isComposite;

	return primes;
}

int main() {
	int m = 35;
	string s(m, 'P');
	s[0] = 'C';
	s[1] = 'C';

	/** Initial printouts */
	cout << "*** Finding primes in the first " << m << " numbers:" << endl;
	cout << "\t\t\t";
	int i = 0;
	while (i < m) {
		if (i + 10 <= m) {
			cout << "0123456789";
		}
		else {
			for (int j = 0; j < (m - i); j++) {
				cout << j;
			}
		}
		i += 10;
	}
	cout << endl;

	cout << "Initial:\t\t" << s << endl;

	/** Sieve of Eratosthenes, print first 200 primes */

	for (int prime : findPrimes(m)) {
		cout << prime << " ";
	}
	cout << endl;

	/** Sieve of Eratosthenes, print largest prime under 100,000 */
	cout << "\n*** Finding the largest prime in the first 100,000 numbers:" << endl;
	vector<int> p = findPrimes(100000);
	cout << p[p.size() - 1] << endl;

	return 0;
}