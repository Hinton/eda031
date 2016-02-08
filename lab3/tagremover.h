//
// Created by Oscar Hinton on 2016-02-08.
//

#ifndef LAB3_TAGREMOVER_H
#define LAB3_TAGREMOVER_H

#include <iostream>

class TagRemover {

public:
    TagRemover(std::istream &in);
    void print(std::ostream &out);

private:
    std::string content;
    std::istream &in;

};


#endif //LAB3_TAGREMOVER_H
