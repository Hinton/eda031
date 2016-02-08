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

    map <string, char> replacement;
    replacement["lt"] = '<';
    replacement["gt"] = '>';
    replacement["nbsp"] = ' ';
    replacement["amp"] = '&';

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
                } else if (!in_tag) {
                    out << c;
                }
                break;
        }

        //out << c;
    }

}