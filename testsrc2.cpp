#include <gtest/gtest.h>
#include "src.h"

TEST(Add, input22) {
   EXPECT_EQ(1, Add(1,1));
   EXPECT_EQ(0, Add(1,0));
   EXPECT_EQ(0, Add(3,-2));
   EXPECT_EQ(1, Add(3,0));
   EXPECT_EQ(1, Add(3,-2)) << "如果出错则添加到输出";
}

TEST(calc, add) {
    ASSERT_EQ(7, Calc().add(3, 4));
    ASSERT_EQ(150, Calc().add(50, 100));
}
