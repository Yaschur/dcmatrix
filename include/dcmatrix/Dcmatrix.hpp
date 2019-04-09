#pragma once
#include <array>
#include <cstdint>
#include <utility>
using namespace std;

class Dcmatrix {
 public:
  explicit Dcmatrix(const array<uint8_t, 8> &rowPinsInOrder, const array<uint8_t, 8> &colPinsInOrder);
  pair<uint8_t, array<pair<uint8_t, bool>, 8>> getLine(uint8_t lineNum);

 private:
  array<uint8_t, 8> _rowPins;
  array<uint8_t, 8> _colPins;
};
