#pragma once

#include <cstdint>
using namespace std;

class Facet3 {
 public:
  explicit Facet3(uint8_t row, uint8_t col);
  void setLines(uint8_t row1, uint8_t row2, uint8_t row3);
  void drawTo(uint8_t matrix[8]);

 private:
  uint8_t _row;
  uint8_t _off;
  uint8_t _mask;
  uint8_t _lines[3];
};
