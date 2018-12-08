/**
 * router.h
 *
 * Created by Gahl Goziker on 12/4/18.
 *
 * Simulates receiving an IPv4 packet, routing it through a lookup table using
 * principle of longest match.
 * Table is hardcoded in router constructor.
 */


#ifndef ROUTING_SWITCHING_SOFTWARE_ROUTER_H
#define ROUTING_SWITCHING_SOFTWARE_ROUTER_H
#include <iostream>
#include "routingTable.h"
using namespace std;


class Router {



public:


    // struct that will hold an IPv4 packet
    struct packet{
        // 160 bits in the header
        bitset<4> version;
        bitset<4> hlen;
        bitset<8> tos;
        bitset<16> length;
        bitset<16> dent;
        bitset<4> flags;
        bitset<13> offset;
        bitset<8> ttl;
        bitset<8> protocol;
        bitset<16> checksum;
        bitset<32> sourceaddr;
        bitset<32> destaddr;
        bitset<24> options;
        bitset<8> pad;

        // data stored as string
        string data;
    };

    //Initializes forwarding table
    Router(bool debug);
    void route(packet p);
    void printTable();



private:
    /** Determines whether debugging messages should be printed */
    bool debug;
    routingTable* table;
    friend ostream& operator<<(ostream& os, const packet& p);

};




#endif //ROUTING_SWITCHING_SOFTWARE_ROUTER_H
