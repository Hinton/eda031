#include <iostream>
#include <fstream>
#include "coding.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "No filename specified" << endl;
        return 0;
    }

    string filename = string(argv[1]);

    ifstream in;
    ofstream out;

    in.open(filename);
    out.open(filename + ".enc");

    char c;
    while (in.get(c)) {
        out << Coding::encode(c);
    }

    in.close();
    out.close();

    cout << "Finnished encoding the file " << filename << endl;
}