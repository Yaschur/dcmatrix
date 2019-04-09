#pragma once

#include <array>
#include <cstdint>
using namespace std;

class Facet3 {
 public:
  explicit Facet3(uint8_t row, uint8_t col);
  void setLines(const std::array<uint8_t, 3> &rows);
  void drawTo(std::array<uint8_t, 8> &matrix);

 private:
  uint8_t _row;
  uint8_t _off;
  uint8_t _mask;
  std::array<uint8_t, 3> _lines;
};
