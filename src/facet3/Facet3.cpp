#include "Facet3.hpp"

Facet3::Facet3(unsigned char row, unsigned char col) : _off(5 - col), _row(row), _mask(~(0b00000111 << _off)) {}

void Facet3::setLines(unsigned char rows[3]) {
  for (int i = 0; i < 3; i++) {
    _lines[i] = (rows[i] << _off) & ~_mask;
  }
}

void Facet3::drawTo(unsigned char matrix[8]) {
  for (int i = 0; i < 3; i++) {
    int ind = _row + i;
    matrix[ind] &= _mask;
    matrix[ind] |= _lines[i];
  }
}
