//
// Created by Gahl Goziker on 12/4/18.
//

#include "router.h"


/**
 * Create a router
 * Hardcode the routing table
 */
Router::Router(bool debug) : debug(debug) {
  this->table = new routingTable(debug);
  // Route 1: 0.0.0.0/0
  table->addEntry({bitset<32>(), 0, "interface 1"});

  // Route 2: 1.2.3.4/8
  table->addEntry({bitset<32> (0x01020304), 8, "interface 2"});

  // Route 3: 1.2.3.4/16
  table->addEntry({bitset<32> (0x01020304), 16, "interface 3"});

  // Route 4: 1.2.3.128 /30
  table->addEntry({bitset<32> (0x01020380), 25, "interface 4"});


}



void Router::route(Router::packet p) {
  if(debug){cout << "packet to route: " << p << endl;}
  routingTable::routingTableEntry entry = table->lookup(p.destaddr);
  // If no match
  if(entry.mask == -1){return;}
  cout << "packet \t\t\t" << p << "\nrouted to\t\t" << entry << endl;
}



void Router::printTable() {
  cout << "Forwarding table: " << *this->table << endl;
}



ostream& operator<<(ostream& os, const Router::packet& p) {
  for(int i = 31; i>0; i--){
    os << p.destaddr[i];
    if((i)%8 == 0){cout << ".";}
  }
  os << p.destaddr[0];
  return os;
}