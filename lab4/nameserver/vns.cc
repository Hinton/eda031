#include <algorithm>
#include "vns.h"

using namespace std;

VNS::VNS() {

}

VNS::~VNS() {

}

void VNS::insert(const HostName &h, const IPAddress &ip) {
    vec.push_back(make_pair(h, ip));
}

bool VNS::remove(const HostName &h) {

    // Find the pair
    auto it = find_if(vec.begin(), vec.end(), [h](const pair<HostName, IPAddress>& e) {
        return e.first == h;
    });

    if (it == vec.end()) {
        return false;
    }

    vec.erase(it);

    return true;
}

IPAddress VNS::lookup(const HostName &h) const {

    // Find the pair
    auto it = find_if(vec.begin(), vec.end(), [h](const pair<HostName, IPAddress>& e) {
       return e.first == h;
    });

    if (it == vec.end()) {
        return NON_EXISTING_ADDRESS;
    }

    return it->second;
}