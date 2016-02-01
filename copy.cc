#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

string trigrams(string word) {
    std::vector<string> words;

    if (word.length() <= 3) {
        return "0";
    }

    for (int i = 0; i < static_cast<int>(word.length()) - 3; i++) {
        string w = word.substr(i, 3);
        transform(w.begin(), w.end(), w.begin(), ::tolower);

        words.insert(words.begin(), w);
    }
    sort(words.begin(), words.end());

    string ret = to_string(words.size());
    for (std::vector<string>::iterator it = words.begin() ; it != words.end(); ++it) {
        ret += " " + *it;
    }

    return ret;
}

int main() {
    string filename = "/usr/share/dict/words";

    ifstream in;
    ofstream out;

    in.open(filename);
    out.open("words.txt");

    std::string str;
    while (std::getline(in, str))
    {
        out << str << " " << trigrams(str) << "\n";
    }

    in.close();
    out.close();

    cout << "Finnished encoding the file " << filename << endl;
}