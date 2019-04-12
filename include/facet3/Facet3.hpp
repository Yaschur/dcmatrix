#pragma once

class Facet3 {
 public:
  explicit Facet3(unsigned char row, unsigned char col);
  void setLines(unsigned char rows[3]);
  void drawTo(unsigned char matrix[8]);

 private:
  unsigned char _off, _row, _mask;
  unsigned char _lines[3];
};
