#include "Facet3.hpp"

Facet3::Facet3(uint8_t row, uint8_t col) {
  _off = 5 - col;
  _row = row;
  _mask = ~(0b00000111 << _off);
  _lines = {0, 0, 0};
}

void Facet3::setLines(const std::array<uint8_t, 3> &rows) {
  for (auto i = 0; i < _lines.size(); i++) {
    _lines[i] = (rows[i] << _off) & ~_mask;
  }
}

void Facet3::drawTo(std::array<uint8_t, 8> &matrix) {
  for (auto i = 0; i < 3; i++) {
    matrix[_row + i] &= _mask;
    matrix[_row + i] |= _lines[i];
  }
}
