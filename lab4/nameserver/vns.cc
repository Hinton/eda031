#include "vns.h"

VNS::VNS() {

}

VNS::~VNS() {

}

void VNS::insert(const HostName &, const IPAddress &) {

}

bool VNS::remove(const HostName &) {
    return false;
}

IPAddress VNS::lookup(const HostName &) {
    return NON_EXISTING_ADDRESS;
}