#pragma once
#include "Facet3.hpp"

class Dcmatrix {
 public:
  Dcmatrix();
  void addFacet();
  unsigned char getFacetsNum();
  void setPic(unsigned char facet, unsigned char pic[3]);
  void fillLine(unsigned char row, bool lineBuffer[8]);

 private:
  Facet3 _facets[4];
  unsigned char _matrix[8];
  unsigned char _facetsNum;
};
