//
// Created by Oscar Hinton on 2016-02-08.
//

#include <regex>
#include <map>
#include "tagremover.h"

using namespace std;


TagRemover::TagRemover(std::istream &in) : in(in) {

}

void TagRemover::print(std::ostream &out) {

    map <string, string> replacement;
    replacement["&lt;"] = "<";
    replacement["&gt;"] = ">";
    replacement["&nbsp;"] = " ";
    replacement["&amp;"] = "&";

    string s(std::istreambuf_iterator<char>(in), {});

    size_t startPos = s.find("<", 0);
    size_t endPos = s.find(">", 0);
    while (startPos != string::npos && endPos != string::npos)
    {
        int length = endPos - startPos + 1;

        string inside = s.substr(startPos, length);
        int newlines = count(inside.begin(), inside.end(), '\n');

        s.erase(startPos, length);
        if (newlines > 0) {
            s.insert(startPos, "\n");
        }

        startPos = s.find("<", 0);
        endPos = s.find(">", 0);
    }

    typedef map<string, string>::iterator it_type;
    for (it_type iterator = replacement.begin(); iterator != replacement.end(); iterator++) {
        size_t pos = s.find(iterator->first, 0);
        while (pos != string::npos) {

            s.replace(pos, iterator->first.length(), iterator->second);

            pos = s.find(iterator->first, 0);
        }
    }

    out << s;

    /*

    cout << s;

    char c;
    bool in_tag = false;
    bool in_html_tag = false;
    string tag = "";

    while (in.get(c)) {

        switch (c) {

            case '<':
                in_tag = true;
                break;

            case '>':
                in_tag = false;
                break;

            case '&':
                tag = "";
                in_html_tag = true;
                break;

            case ';':
                in_html_tag = false;
                if (replacement.count(tag)) {
                    out << replacement[tag];
                }
                tag = "";
                break;

            default:
                if (in_html_tag) {
                    tag += c;
                } else if (c == '\n' || !in_tag) {
                    out << c;
                }
                break;
        }

        //out << c;
    }
     */

}