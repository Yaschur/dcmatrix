#include "Facet3.hpp"

Facet3::Facet3(uint8_t row, uint8_t col) : _off(5 - col), _row(row), _mask(~(0b00000111 << _off)), _lines({0, 0, 0}) {}
Facet3::~Facet3() {}

void Facet3::setLines(const std::array<uint8_t, 3> &rows) {
  for (uint8_t i = 0; i < 3; i++) {
    _lines[i] = (rows[i] << _off) & ~_mask;
  }
}

void Facet3::drawTo(std::array<uint8_t, 8> &matrix) {
  for (uint8_t i = 0; i < 3; i++) {
    uint8_t ind = _row + i;
    matrix[ind] &= _mask;
    matrix[ind] |= _lines[i];
  }
}
