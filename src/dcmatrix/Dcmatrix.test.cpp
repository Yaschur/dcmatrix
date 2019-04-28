#include "Dcmatrix.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class DcmatrixTests : public testing::Test {};

TEST(DcmatrixTests, new_matrix_has_one_facet) {
  Dcmatrix matrix;

  auto num = matrix.getFacetsNum();

  ASSERT_EQ(1, num);
}

TEST(DcmatrixTests, add_facet_to_matrix) {
  Dcmatrix matrix;

  matrix.addFacet();
  auto num = matrix.getFacetsNum();

  ASSERT_EQ(2, num);
}

TEST(DcmatrixTests, add_facet_to_full_matrix) {
  Dcmatrix matrix;
  matrix.addFacet();
  matrix.addFacet();
  matrix.addFacet();

  matrix.addFacet();
  auto num = matrix.getFacetsNum();

  ASSERT_EQ(1, num);
}

TEST(DcmatrixTests, fill_lines) {
  Dcmatrix matrix;
  bool buffer[8];
  unsigned char pic1[3] = {0b001, 0b010, 0};
  unsigned char pic2[3] = {0b001, 0b010, 0b001};
  unsigned char pic3[3] = {0b110, 0b100, 0b010};
  bool exps[8][8] = {
      {false, false, true, false, false, true, true, false},   {false, true, false, false, false, true, false, false},
      {false, false, false, false, false, false, true, false}, {false, false, false, true, true, false, false, false},
      {false, false, false, false, true, false, false, false}, {false, false, false, false, false, false, false, true},
      {false, false, false, false, false, false, true, false}, {false, false, false, false, false, false, false, true}};
  matrix.addFacet();
  matrix.addFacet();
  matrix.setPic(0, pic1);
  matrix.setPic(1, pic2);
  matrix.setPic(2, pic3);
  matrix.setPic(3, pic2);

  for (int i = 0; i < 8; i++) {
    matrix.fillLine(i, buffer);
    ASSERT_THAT(buffer, testing::ElementsAreArray(exps[i]));
  }
}
