#pragma once
#include <array>
#include <cstdint>
#include <utility>
#include "Facet3.hpp"
using namespace std;

class Dcmatrix {
 public:
  explicit Dcmatrix(const array<uint8_t, 8> &rowPinsInOrder, const array<uint8_t, 8> &colPinsInOrder);
  void addFacet();
  uint8_t getFacetsNum();
  pair<uint8_t, array<pair<uint8_t, bool>, 8>> getLine(uint8_t lineNum);

 private:
  array<uint8_t, 8> _rowPins, _colPins;
  array<Facet3, 4> _facets;
  uint8_t _facetsNum;
};
