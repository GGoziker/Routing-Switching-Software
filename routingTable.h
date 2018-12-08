//
// Created by Gahl Goziker on 12/4/18.
//

#ifndef ROUTING_SWITCHING_SOFTWARE_ROUTINGTABLE_H
#define ROUTING_SWITCHING_SOFTWARE_ROUTINGTABLE_H

#include <iostream>
#include <list>
using namespace std;


class routingTable {




public:
    /**
     * An entry in the routing table
     */
    struct routingTableEntry{
         bitset<32> dest;   // IP address
        int mask;
        string interface;
        routingTableEntry(bitset<32> dest, int mask,
                          string inf): dest(dest),mask(mask), interface(inf){}
    };
    bool debug;
    routingTable(bool debug);
    routingTableEntry lookup(bitset<32> address) const; //@todo WORKS
    void addEntry(routingTableEntry entry);



private:
    list<routingTableEntry> routes;
    friend ostream& operator<<(ostream& os, const routingTable& table);
    friend ostream& operator<<(ostream& os, const routingTableEntry& route);
};


#endif //ROUTING_SWITCHING_SOFTWARE_ROUTINGTABLE_H
