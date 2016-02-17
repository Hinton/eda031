//
// Created by Oscar Hinton on 2016-02-15.
//

#ifndef NAMESERVER_VNS_H
#define NAMESERVER_VNS_H

#include <vector>
#include "nameserverinterface.h"

class VNS : public NameServerInterface {
public:

    VNS();
    ~VNS();

    /*
     * Insert a name/address pair. Does not check if the name
     * or address already exists.
     */
    void insert(const HostName&, const IPAddress&);

    /*
     * Remove the pair with the specified host name. Returns true
     * if the host name existed and the pair was removed, false
     * otherwise.
     */
    bool remove(const HostName&);

    /*
     * Find the IP address for the specified host name. Returns
     * NON_EXISTING_ADDRESS if the host name wasn't in the name
     * server.
     */
    IPAddress lookup(const HostName&) const;

private:
    std::vector<std::pair<HostName, IPAddress>> vec;
};


#endif //NAMESERVER_VNS_H
