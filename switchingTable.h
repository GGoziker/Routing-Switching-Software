//
// Created by Gahl Goziker on 12/7/18.
//

#ifndef ROUTING_SWITCHING_SOFTWARE_SWITCHINGTABLE_H
#define ROUTING_SWITCHING_SOFTWARE_SWITCHINGTABLE_H

#include <iostream>
#include <list>
using namespace std;


class switchingTable {
    friend class Switch;

public:
    /**
     * An entry in the routing table
     */
    struct switchingTableEntry{
        // MAC address
        bitset<48> dest;
        string interface;
        switchingTableEntry(bitset<48> mac, string inf): dest(mac), interface(inf){}
    };
    bool debug;
    switchingTable(bool debug);
    switchingTableEntry lookup(switchingTableEntry target);
    void addEntry(switchingTableEntry entry);



private:
    list<switchingTableEntry> routes;
    friend ostream& operator<<(ostream& os, const switchingTable& table);
    friend ostream& operator<<(ostream& os, const switchingTableEntry& route);
};


#endif //ROUTING_SWITCHING_SOFTWARE_SWITCHINGTABLE_H
