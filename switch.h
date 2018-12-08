/**
 * switch.h
 *
 * Created by Gahl Goziker on 12/4/18.
 *
 * Simulates receiving an Ethernet frame, forwarding it through a lookup table.
 * Table is initially empty, builds up as packets travel through the switch.
 */

#ifndef ROUTING_SWITCHING_SOFTWARE_SWITCH_H
#define ROUTING_SWITCHING_SOFTWARE_SWITCH_H

#include <iostream>
#include "switchingTable.h"
using namespace std;


class Switch {



public:


    // struct that will hold an Ethernet framet
    struct frame{
        // 160 bits in the header
        bitset<64> preamble;
        bitset<48> destAddr;
        bitset<48> sourceAddr;
        bitset<16> type;
        string data;
        bitset<4> crc;
    };

    //Initializes debug variable
    Switch(bool debug);
    /** Filter frame if necessary, forward if not */
    void forward(switchingTable::switchingTableEntry input);
    void printTable();



private:
    bool debug;
    switchingTable* table;
    friend ostream& operator<<(ostream& os, const frame& f);

};


#endif //ROUTING_SWITCHING_SOFTWARE_SWITCH_H
