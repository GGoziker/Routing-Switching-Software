//
// Created by Gahl Goziker on 12/7/18.
//

#include "switchingTable.h"



switchingTable::switchingTable(bool debug) : debug(debug){}



/**
 * lookup
 *
 * Search for a table entry whose dest matches target's dest.
 * If found, return that entry.
 * If not, add target to table and return empty entry with interface=="not found".
 *
 * @param target    entry with dest = mac to find, interface = input interface
 * @return          switchingTableEntry representing the search result
 */
switchingTable::switchingTableEntry switchingTable::lookup(switchingTableEntry target) {
  for(switchingTableEntry entry : routes){
    // If match found, return match
    if(entry.dest == target.dest){return entry;}
  }
  // If no match found, add to table and return empty entry
  addEntry(target);
  return switchingTableEntry {bitset<48>(), "not found"};
}



/**
 * addEntry
 *
 * Add entry to the switchingTable's list of entries.
 * @param entry entry to add
 */
void switchingTable::addEntry(switchingTable::switchingTableEntry entry) {
  routes.push_back(move(entry));
}



ostream &operator<<(ostream &os, const switchingTable &table) {
  if(table.routes.size()==0){
    os << "table is empty\n";
  }else {
    os << "\nMAC address\t\t\t\t\t\t\t\t\t\t\t\t\tinterface" << endl;
    for (const switchingTable::switchingTableEntry entry : table.routes) {
      os << entry;
    }
  }
  return os;
}



ostream &operator<<(ostream &os, const switchingTable::switchingTableEntry &route) {
  // Print all bits in route's destination
  for(int i = 47; i>0; i--){
    os << route.dest[i];
    if((i)%8 == 0){os << ".";}
  }
  os << route.dest[0];
  // Print interface
  os << "\t\t" << route.interface << endl;
  return os;
}