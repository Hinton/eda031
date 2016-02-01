#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {

	ifstream in;
	in.open("words.txt");

	std::string str;
	while (std::getline(in, str))
	{
		std::string::size_type pos = str.find(' ');
		if (pos != std::string::npos)
		{
			//words.insert(str.substr(0, pos));
		}
		else
		{
			//words.insert(str);
		}
	}
}

bool Dictionary::contains(const string& word) const {

	for (vector<Word>::iterator it = words.begin(); it != words.end(); ++it) {
		if (*it->get_word().compare(word) == 0) {
			return true;
		}
	}

	return false;

	//std::unordered_set<std::string>::const_iterator got = words.find(word);
	//return got != words.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
