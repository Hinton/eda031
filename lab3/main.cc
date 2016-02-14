#include <iostream>
#include <fstream>
#include "tagremover.h"

using namespace std;

int main() {

    TagRemover tr(cin);
    tr.print(cout);

    return 0;
}