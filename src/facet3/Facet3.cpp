#include "Facet3.hpp"

Facet3::Facet3(uint8_t row, uint8_t col) {
  _off = 5 - col;
  _row = row;
  _mask = ~(0b00000111 << _off);
}

void Facet3::setLines(uint8_t row1, uint8_t row2, uint8_t row3) {
  _lines[0] = (row1 << _off) & ~_mask;
  _lines[1] = (row2 << _off) & ~_mask;
  _lines[2] = (row3 << _off) & ~_mask;
}

void Facet3::drawTo(uint8_t matrix[8]) {
  for (uint8_t i = 0; i < 3; i++) {
    matrix[_row + i] &= _mask;
    matrix[_row + i] |= _lines[i];
  }
}
