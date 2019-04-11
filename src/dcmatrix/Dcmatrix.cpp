#include "Dcmatrix.hpp"

Dcmatrix::Dcmatrix(const array<uint8_t, 8> &rowPinsInOrder, const array<uint8_t, 8> &colPinsInOrder)
    : _rowPins(rowPinsInOrder),
      _colPins(colPinsInOrder),
      _facets{Facet3{0, 0}, Facet3{5, 5}, Facet3{0, 5}, Facet3{5, 0}},
      _facetsNum(1) {}

void Dcmatrix::addFacet() { _facetsNum += (_facetsNum == 4 ? -3 : 1); }
uint8_t Dcmatrix::getFacetsNum() { return _facetsNum; }

pair<uint8_t, array<pair<uint8_t, bool>, 8>> Dcmatrix::getLine(uint8_t lineNum) {
  array<pair<uint8_t, bool>, 8> cols = {make_pair(0, false), make_pair(0, false), make_pair(0, false),
                                        make_pair(0, false), make_pair(0, false), make_pair(0, false),
                                        make_pair(0, false), make_pair(0, false)};
  return make_pair(lineNum, cols);
}
