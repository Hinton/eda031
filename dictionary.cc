#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {

	ifstream in;
	in.open("words.txt");

	string line;
	while (getline(in, line)) {
		stringstream lineStream(line);

		string word;
		lineStream >> word;

		int count;
		lineStream >> count;

		vector<string> trigrams;
		for (int i = 0; i < count; i++) {
			string t;
			in >> t;

			trigrams.push_back(t);
		}

		words[word.size()].push_back(Word(word, trigrams));
	}
}

bool Dictionary::contains(const string& word) const {
	for (Word w : words[word.size()]) {
		if (w.get_word().compare(word) == 0) {
			return true;
		}
	}

	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(std::vector<std::string> vector, const std::string &basic_string) const {

}

void Dictionary::rank_suggestions(std::vector<std::string> vector, const std::string &basic_string) const {

}

void Dictionary::trim_suggestions(std::vector<std::string> vector) const {

}
