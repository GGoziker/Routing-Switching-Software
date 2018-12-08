#include <iostream>
#include "router.h"
#include "switch.h"
using namespace std;

void routerTest(bool);
void switchTest(bool);

int main() {
  // Determine whether to run with debug output
  int input = -1;
  bool debug;

  while (input != 0 && input != 1) {
    cout << "If you want to print runtime information during execution, enter 1."
            " If not, enter 0." << endl;
    cin >> input;
  }
  if (input == 0) debug = false;
  else debug = true;

  routerTest(debug);
  switchTest(true);
  return 0;
}



void routerTest(bool debug){
  cout << "\n\n\n\n\n\n\n\n\n\n\n------------------------------------------"
          "----------------------------------------------"
          "\nROUTER TEST\n-------------------------------------------------"
          "---------------------------------------\nSimulates receiving an IPv4"
          "packet, routing it through a lookup table using principle of longest"
          "match.\nTable is hardcoded in router constructor.\n\n" << endl;

  Router r(debug);
  r.printTable();
  Router::packet p;

  p.destaddr = bitset<32>(0xFFFFFFFF);
  r.route(p);

  p.destaddr = bitset<32>(0x01010304);
  r.route(p);

  p.destaddr = bitset<32>(0x01030304);
  r.route(p);

  p.destaddr = bitset<32>(0x01020404);
  r.route(p);

  p.destaddr = bitset<32>(0x010203AA);
  r.route(p);
}



void switchTest(bool debug){
  cout << "\n\n\n\n\n\n\n\n\n\n--------------------------------------------"
          "--------------------------------------------\n"
          "SWITCH TEST\n---------------------------------------------------"
          "-------------------------------------\nSimulates receiving an"
          "Ethernet frame, forwarding it through a lookup table.\nTable is"
          "initially empty, builds up as packets travel through the switch."
          "\n\n" << endl;

  Switch s(debug);
  s.printTable();
  Switch::frame f;

  // New entry; broadcast
  switchingTable::switchingTableEntry e{bitset<48>(0xFFFFFFFFFFFF), "1"};
  s.forward(e);
  s.printTable();

  // New entry; broadcast
  e = switchingTable::switchingTableEntry{bitset<48>(0x010103040506), "2"};
  s.forward(e);
  s.printTable();

  // Should route to interface 2
  e = switchingTable::switchingTableEntry{bitset<48>(0x010103040506), "1"};
  s.forward(e);
  s.printTable();

  // New entry; broadcast
  e = switchingTable::switchingTableEntry{bitset<48>(0x010303040506), "3"};
  s.forward(e);
  s.printTable();

  // Should route to interface 3; input interface matches output interface; should drop
  e = switchingTable::switchingTableEntry{bitset<48>(0x010303040506), "3"};
  s.forward(e);
  s.printTable();
}