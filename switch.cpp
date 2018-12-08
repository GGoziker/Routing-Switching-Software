//
// Created by Gahl Goziker on 12/4/18.
//

#include "switch.h"



Switch::Switch(bool debug) : debug(debug) {table = new switchingTable(debug);}



/**
 * forward
 *
 * Forward or discard or broadcast the frame appropriately.
 *
 * @param f frame passed into switch
 */
void Switch::forward(switchingTable::switchingTableEntry input) {

  // Wrapper for the ethernet frame being forwarded
  Switch::frame f;
  f.destAddr = input.dest;
  if(debug){cout << "Attempting to forward " << f << " from interface " << input.interface << endl;}

  switchingTable::switchingTableEntry output = table->lookup(input);

  // If input interface matches output interface
  if (input.interface == output.interface) {
    if (debug) {
      cout << "Output interface matches input interface."
              "\nDiscarding frame " << f << endl;
    }
    // Discard frame
    return;

  // If an entry is found for destination address
  }else if(output.interface != "not found"){
    if(debug){cout << "frame \t\t\t" << f << "\nforwarded to\t\t" << output;}

  // If no entry is found for destination address
  }else {
    if(debug){cout << "no entry found for frame " << f << endl;}
    // Broadcast the frame to all interfaces except input
    for(switchingTable::switchingTableEntry output : table->routes){
      if(output.interface != input.interface){
        cout << "frame \t\t\t" << f << "\nbroadcast to\t" << output;
      }
    }
  }
}



void Switch::printTable() {
  cout << "Switch table: " << *this->table << "\n" << endl;
}



/**
 * Print the frame's destination address
 */
ostream &operator<<(ostream &os, const Switch::frame &f) {
  for(int i = 47; i>=0; i--){
    os << f.destAddr[i];
    if((i)%8 == 0 && i!=0){cout << ".";}
  }
  return os;
}
