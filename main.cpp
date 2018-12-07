#include <iostream>
#include "router.h"
using namespace std;


int main() {

  // Determine whether to run with debug output
  int input = -1;
  bool debug;
  while (input != 0 && input != 1) {
    cout << "enter 1 for debug mode, 0 for silent mode" << endl;
    cin >> input;
  }
  if (input == 0) debug = false;
  else debug = true;


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

  return 0;
}