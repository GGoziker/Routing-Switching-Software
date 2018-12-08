//
// Created by Gahl Goziker on 12/4/18.
//

#include "routingTable.h"



routingTable::routingTable(bool debug) : debug(debug){}



/**
 * Search table for a route which matches address.
 * If multiple found, select the one with longest match.
 *
 * @param address   address being routed to
 * @return          routingTableEntry which best fits address
 */
routingTable::routingTableEntry routingTable::lookup(bitset<32> address) const{
  bool notMatch;
  routingTableEntry retVal{bitset<32> (0x01020304), -1, "default"};
  int longestMask = -1;

  // Check every route entered in table
  for(routingTableEntry route : routes) {
    if(debug){cout << "route: " << route << flush;}
    notMatch = false;
    // If route couldn't be longest match, skip route
    if (route.mask <= longestMask) { continue; }
    // If address doesn't match route, skip route
    for (int i = 0; i < route.mask; i++) {
      if(debug){cout << "comparing address bit " << address[31 - i] << " to route bit " << route.dest[31 - i] << endl;}
      if (address[31 - i] != route.dest[31 - i]) {
        notMatch = true;
        break;
      }
    }
    if (notMatch) {
      if(debug){cout << "not a match"<<endl;}
      continue;
    } else {
      // If this line reached, route is longest match
      if(debug){cout << "match!"<<endl;}
      retVal = route;
      longestMask = route.mask;
    }

  }
  if(longestMask == -1) {
    if(debug){cout << "\nNo match found" << endl;}
  }
  return retVal;
}



/**
 * Add entry to the routingTable's list of entries
 * @param entry     route to be added
 */
void routingTable::addEntry(routingTableEntry entry){
  routes.push_back(move(entry));
}



ostream& operator<<(ostream& os, const routingTable::routingTableEntry& route) {
  // Print all bits in route's destination
  for(int i = 31; i>0; i--){
    os << route.dest[i];
    if((i)%8 == 0){os << ".";}
  }
  os << route.dest[0];
  // Print netmask
  os << "\t\t";
  os << route.mask << "\t\t\t"
     << route.interface << endl;
  return os;
}



ostream& operator<<(ostream &os, const routingTable &table) {
  os << "\ndest\t\t\t\t\t\t\t\t\tmask\t\tinterface"<< endl;
  for(const routingTable::routingTableEntry route : table.routes){
    os << route;
  }
  return os;
}
