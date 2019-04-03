#include <bitset>
#include <iostream>
#include "Facet3.hpp"

int main() {
  Facet3 f1(1, 2);
  f1.setLines(0b101, 0, 0b010);
  uint8_t matrix[] = {0b01000010, 0b01000101, 0b01111101, 0b01000101, 0b01000101, 0b01010101, 0b01011101, 0b11000101};
  uint8_t extrix[] = {0b01000010, 0b01101101, 0b01000101, 0b01010101, 0b01000101, 0b01010101, 0b01011101, 0b11000101};
  f1.drawTo(matrix);

  bool bad = false;
  for (int i = 0; i < 8; i++) {
    if (matrix[i] != extrix[i]) {
      bad = true;
      cout << bitset<8>(matrix[i]) << " : " << i << " : ";
    }
    cout << bitset<8>(extrix[i]) << endl;
  }

  cout << endl << "result: " << (bad ? "false" : "true") << endl;
}
