#include <algorithm>
#include "umns.h"

using namespace std;

UMNS::UMNS() {

}

UMNS::~UMNS() {

}

void UMNS::insert(const HostName &h, const IPAddress &ip) {
    m.insert({h, ip});
}

bool UMNS::remove(const HostName &h) {
    return m.erase(h); // Returns an integer [0, 1] = [false, true]
}

IPAddress UMNS::lookup(const HostName &h) const {
    auto it = m.find(h);

    if (it == m.end()) {
        return NON_EXISTING_ADDRESS;
    }

    return it->second;
}