#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigrams = t;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int matches = 0;

	vector<string>::iterator w_it = words.begin();
	vector<string>::iterator t_it = t.begin();

	while (w_it != words.end() && t_it != t.end()) {
		int cmp = *w_it.compare(*t_it);

		if (cmp == 0) {
			matches++;
			w_it++;
			t_it++;
		} else if (cmp < 0) {
			w_it++;
		} else {
			t_it++;
		}
	}

	return matches;
}
