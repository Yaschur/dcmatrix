#include "Dcmatrix.hpp"

Dcmatrix::Dcmatrix(const array<uint8_t, 8> &rowPinsInOrder, const array<uint8_t, 8> &colPinsInOrder)
    : _rowPins(rowPinsInOrder), _colPins(colPinsInOrder) {}

pair<uint8_t, array<pair<uint8_t, bool>, 8>> Dcmatrix::getLine(uint8_t lineNum) {
  array<pair<uint8_t, bool>, 8> cols = {make_pair(0, false), make_pair(0, false), make_pair(0, false),
                                        make_pair(0, false), make_pair(0, false), make_pair(0, false),
                                        make_pair(0, false), make_pair(0, false)};
  return make_pair(lineNum, cols);
}
