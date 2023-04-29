#include "lib.h"

#include <gtest/gtest.h>

TEST(CheckVersionTest, CheckVersionSuccess) {
  ASSERT_TRUE(version() > 0);
}
