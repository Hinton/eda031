#include <algorithm>
#include "mns.h"

using namespace std;

MNS::MNS() {

}

MNS::~MNS() {

}

void MNS::insert(const HostName &h, const IPAddress &ip) {
    m.insert({h, ip});
}

bool MNS::remove(const HostName &h) {
    return m.erase(h); // Returns an integer [0, 1] = [false, true]
}

IPAddress MNS::lookup(const HostName &h) const {
    auto it = m.find(h);

    if (it == m.end()) {
        return NON_EXISTING_ADDRESS;
    }

    return it->second;
}