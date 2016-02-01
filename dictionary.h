#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include "word.h"

#define DICTIONARY_WORD_LENGTH 25

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	//std::unordered_set<std::string> words;
	std::vector<Word> words[DICTIONARY_WORD_LENGTH];

	void add_trigram_suggestions(std::vector<Word> vector, const std::string &word) const;

	void rank_suggestions(std::vector<Word> vector, const std::string &word) const;

	void trim_suggestions(std::vector<Word> vector) const;
};

#endif
