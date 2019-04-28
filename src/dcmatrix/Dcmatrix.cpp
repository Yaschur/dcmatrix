#include "Dcmatrix.hpp"

Dcmatrix::Dcmatrix() : _facets({Facet3(0, 0), Facet3(5, 5), Facet3(0, 5), Facet3(5, 0)}), _matrix{}, _facetsNum(1) {}

void Dcmatrix::addFacet() {
  _facetsNum += (_facetsNum == 4 ? -3 : 1);
  switch (_facetsNum) {
    case 1:
      _matrix[3] = 0b00010000;
      _matrix[4] = 0;
      break;
    case 2:
      _matrix[3] = 0b00010000;
      _matrix[4] = 0b00001000;
      break;
    case 3:
      _matrix[3] = 0b00011000;
      _matrix[4] = 0b00001000;
      break;
    case 4:
      _matrix[3] = 0b00011000;
      _matrix[4] = 0b00011000;
      break;
  }
}

void Dcmatrix::setPic(unsigned char facet, unsigned char pic[3]) {
  if (facet > _facetsNum - 1) return;

  _facets[facet].setLines(pic);
  _facets[facet].drawTo(_matrix);
}

unsigned char Dcmatrix::getFacetsNum() { return _facetsNum; }

void Dcmatrix::fillLine(unsigned char row, bool lineBuffer[8]) {
  for (int i = 0; i < 8; i++) {
    lineBuffer[i] = (_matrix[row] >> (7 - i)) & 1;
  }
}
