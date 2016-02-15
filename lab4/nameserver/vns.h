//
// Created by Oscar Hinton on 2016-02-15.
//

#ifndef NAMESERVER_VNS_H
#define NAMESERVER_VNS_H


class VNS : public NameServerInterface {
public:

    VNS();

    /*
     * Insert a name/address pair. Does not check if the name
     * or address already exists.
     */
    void insert(const HostName&, const IPAddress&) = 0;

    /*
     * Remove the pair with the specified host name. Returns true
     * if the host name existed and the pair was removed, false
     * otherwise.
     */
    bool remove(const HostName&) = 0;

    /*
     * Find the IP address for the specified host name. Returns
     * NON_EXISTING_ADDRESS if the host name wasn't in the name
     * server.
     */
    IPAddress lookup(const HostName&) const = 0;
};


#endif //NAMESERVER_VNS_H
