#include "Facet3.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Facet3Tests : public testing::Test {};

TEST(Facet3Tests, draw) {
  Facet3 f1(1, 2);
  f1.setLines({0b101, 0, 0b010});
  std::array<uint8_t, 8> matrix = {0b01000010, 0b01000101, 0b01111101, 0b01000101, 0b01000101, 0b01010101, 0b01011101, 0b11000101};
  uint8_t extrix[] = {0b01000010, 0b01101101, 0b01000101, 0b01010101, 0b01000101, 0b01010101, 0b01011101, 0b11000101};

  f1.drawTo(matrix);

  ASSERT_THAT(matrix, testing::ElementsAreArray(extrix));
}
