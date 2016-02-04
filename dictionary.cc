#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <map>
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



void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string &word) const {
	// Search the dictionary and find candidates for corrections (section 2.3).
	// To begin with, the words in the dictionary which have approximately the
	// same number of letters (plus/minus one letter) as the misspelled word
	// should be considered. Of these candidates, the words which contain at
	// least half of the “trigrams” of the misspelled word should be kept.
	// A trigram is three adjacent letters — for example, the word summer
	// contains the trigrams sum umm mme mer.

	vector<Word> possible_words;

	possible_words.insert(possible_words.end(), words[word.size()].begin(), words[word.size()].end());
	possible_words.insert(possible_words.end(), words[word.size()+1].begin(), words[word.size()+1].end());
	possible_words.insert(possible_words.end(), words[word.size()-1].begin(), words[word.size()-1].end());


	// Generate the trigram for word.
	std::vector<string> tri;
	for (int i = 0; i < static_cast<int>(word.length()) - 2; i++) {
		string w = word.substr(i, 3);
		transform(w.begin(), w.end(), w.begin(), ::tolower);
cout << w << " ";
		tri.insert(tri.begin(), w);
	}
	sort(tri.begin(), tri.end());

	for (Word w : possible_words) {
		if (w.get_matches(tri) * 2 >= tri.size()) {
			suggestions.push_back(w.get_word());
		}
	}
}

unsigned int edit_distance(const std::string& s1, const std::string& s2)
{
	const std::size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
			// note that std::min({arg1, arg2, arg3}) works only in C++11,
			// for C++98 use std::min(std::min(arg1, arg2), arg3)
			d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];
}

void Dictionary::rank_suggestions(vector<string> &suggestions, const string &word) const {
	// Sort the candidate list so the “best” candidates are first in the list
	// (section 2.4). The sort key is the cost to change the misspelled word
	// to one of the candidate words.

	map<string,int> cost;
	for (string s : suggestions) {
		cost[s] = edit_distance(s, word);
	}

	sort(suggestions.begin(), suggestions.end(), [&cost](const string& lhs, const string& rhs)
	{
		return cost[lhs] < cost[rhs];
	});
}

void Dictionary::trim_suggestions(vector<string> &suggestions) const {
	// Keep the first 5 candidates in the list (section 2.5).
	if (suggestions.size() > 5) {
		suggestions.resize(5);
	}
}
