//
// Created by Oscar Hinton on 2016-02-15.
//

#ifndef NAMESERVER_HNS_H
#define NAMESERVER_HNS_H


#include <vector>
#include "nameserverinterface.h"

using HashEntry = std::pair<HostName, IPAddress>;

class HNS : public NameServerInterface {
public:
    HNS(size_t size);
    ~HNS();

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
    size_t size;
    std::vector<std::vector<HashEntry>> vec;
};


#endif //NAMESERVER_HNS_H
