#include <gtest/gtest.h>
extern "C" { // 在这里包裹  调用gcc 编译的 C函数
#include "samplemy1_c.h"
}
TEST(cfunc, cadd) {
    ASSERT_EQ(1, cadd(3, 4));
    ASSERT_EQ(1, cadd(50, 100));
}