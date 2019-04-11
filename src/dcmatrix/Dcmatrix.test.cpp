#include "Dcmatrix.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class DcmatrixTests : public testing::Test {};

TEST(DcmatrixTests, new_matrix_has_one_facet) {
  Dcmatrix matrix({1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8});

  auto num = matrix.getFacetsNum();

  ASSERT_EQ(1, num);
}

TEST(DcmatrixTests, add_facet_to_matrix) {
  Dcmatrix matrix({1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8});

  matrix.addFacet();
  auto num = matrix.getFacetsNum();

  ASSERT_EQ(2, num);
}

TEST(DcmatrixTests, add_facet_to_full_matrix) {
  Dcmatrix matrix({1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8});
  matrix.addFacet();
  matrix.addFacet();
  matrix.addFacet();

  matrix.addFacet();
  auto num = matrix.getFacetsNum();

  ASSERT_EQ(1, num);
}
