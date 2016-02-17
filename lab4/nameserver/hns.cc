#include <algorithm>
#include "hns.h"

using namespace std;

HNS::HNS(size_t s) : size(s), vec(size, vector<HashEntry>(1)){
}

HNS::~HNS() {

}

void HNS::insert(const HostName &h, const IPAddress &ip) {
    size_t hash_pos = hash<HostName>()(h) % size;

    // Throw it in last.
    (&vec[hash_pos])->push_back({h, ip});
}

bool HNS::remove(const HostName &h) {
    size_t hash_pos = hash<HostName>()(h) % size;

    auto *v = &vec[hash_pos];

    // Find the pair
    auto it = find_if(v->begin(), v->end(), [h](const pair<HostName, IPAddress>& e) {
        return e.first == h;
    });

    if (it == v->end()) {
        return false;
    }

    v->erase(it);

    return true;
}

IPAddress HNS::lookup(const HostName &h) const {
    size_t hash_pos = hash<HostName>()(h) % size;

    auto v = vec[hash_pos];

    // Find the pair
    auto it = find_if(v.begin(), v.end(), [h](const pair<HostName, IPAddress>& e) {
        return e.first == h;
    });

    if (it == v.end()) {
        return NON_EXISTING_ADDRESS;
    }

    return it->second;
}