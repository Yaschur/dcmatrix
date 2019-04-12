#include "Facet3.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Facet3Tests : public testing::Test {};

TEST(Facet3Tests, draw) {
  Facet3 f1(1, 2);
  unsigned char lines[3] = {0b101, 0, 0b010};
  f1.setLines(lines);
  unsigned char matrix[8] = {0b01000010, 0b01000101, 0b01111101, 0b01000101,
                             0b01000101, 0b01010101, 0b01011101, 0b11000101};
  unsigned char extrix[] = {0b01000010, 0b01101101, 0b01000101, 0b01010101,
                            0b01000101, 0b01010101, 0b01011101, 0b11000101};

  f1.drawTo(matrix);

  ASSERT_THAT(matrix, testing::ElementsAreArray(extrix));
}
