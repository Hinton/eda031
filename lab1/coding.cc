#include "coding.h"

unsigned char Coding::encode(unsigned char c) {
    return static_cast<unsigned char>(c + 1);
}

unsigned char Coding::decode(unsigned char c) {
    return static_cast<unsigned char>(c - 1);
}
