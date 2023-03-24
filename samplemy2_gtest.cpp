#include <gtest/gtest.h>
#include "samplemy2.h"


TEST(FooTest, HandleNoneZeroInput) {
   EXPECT_EQ(2, Foo(4,10));
   EXPECT_EQ(6, Foo(30,18));
}
TEST(Action, input1) {
   EXPECT_EQ(0, Action(1,1));
   EXPECT_EQ(-1, Action(1,2));
   EXPECT_EQ(1, Action(3,2));
}
TEST(Device, input1) {
   EXPECT_EQ(0, Action(1,1));
   EXPECT_EQ(-1, Action(1,2));
   EXPECT_EQ(1, Action(3,2));
   EXPECT_EQ(1, Action(3,0));
}
TEST(Add, input1) {
   EXPECT_EQ(1, Add(1,1));
   EXPECT_EQ(0, Add(1,0));
   EXPECT_EQ(0, Add(3,-2));
   EXPECT_EQ(1, Add(3,0));
   EXPECT_EQ(0, Add(3,-2));
}


// 浮点比较
// Floating-Point Macros
// Fatal assertion               Nonfatal assertion            Verifies
// ASSERT_FLOAT_EQ(val1, val2);  EXPECT_FLOAT_EQ(val1, val2);  the two float values are almost equal
// ASSERT_DOUBLE_EQ(val1, val2); EXPECT_DOUBLE_EQ(val1, val2); the two double values are almost equal
// “几乎相等”是指两个值彼此在4个ULP内。

// 以下断言允许您选择可接受的误差界限：
// Fatal assertion                     Nonfatal assertion                  Verifies
// ASSERT_NEAR(val1, val2, abs_error); EXPECT_NEAR(val1, val2, abs_error); the difference between val1 and val2 doesn't exceed the given absolute error
TEST(float, test1) {
   EXPECT_FLOAT_EQ(1.0000001, 1.0000002);
   // 下面的不相等
   // EXPECT_FLOAT_EQ(1.000001, 1.000002);

   EXPECT_NEAR(1.1, 1.2, 0.2);
   // 下面的不相等
   // EXPECT_NEAR(1.1, 1.2, 0.02);
}

// Windows HRESULT断言
// 这些断言测试HRESULT成功或失败。
// Fatal assertion                       Nonfatal assertion                    Verifies
// ASSERT_HRESULT_SUCCEEDED(expression); EXPECT_HRESULT_SUCCEEDED(expression); expression is a success HRESULT
// ASSERT_HRESULT_FAILED(expression);    EXPECT_HRESULT_FAILED(expression);    expression is a failure HRESULT
// 生成的输出包含与expression返回的HRESULT代码相关联的人工可读错误消息。
// You might use them like this:
TEST(HRESULT, test1) {
   // CComPtr shell;
   // EXPECT_HRESULT_SUCCEEDED(shell.CoCreateInstance(L"Shell.Application"));
   // CComVariant empty;
   // EXPECT_HRESULT_SUCCEEDED(shell->ShellExecute(CComBSTR(url), empty, empty, empty, empty));
}


// 类型断言
// ::testing::StaticAssertTypeEq<T1, T2>();
// 您可以调用该函数，来声称断言类型T1和T2是相同的。 如果满足断言，该函数不执行任何操作。
// 如果类型不同，函数调用将无法编译，编译器错误消息（取决于编译器）将显示T1和T2的实际值。 这主要在模板代码中有用。
// 注意：当在类模板或函数模板的成员函数中使用时，StaticAssertTypeEq <T1，T2>（）仅在函数实例化时有效。例如：
// template <typename T> class Foo {
//  public:
//   void Bar() { ::testing::StaticAssertTypeEq<int, T>(); }
// };
// void Test1() { Foo<bool> foo; }
// 将不会生成编译器错误，因为Foo <bool> :: Bar（）永远不会实际实例化。 相反，您需要：
// void Test2() { Foo<bool> foo; foo.Bar(); }

TEST(StaticAssertTypeEq, test1) {
   ::testing::StaticAssertTypeEq<int, int>();
   // 下面编译出错
   // ::testing::StaticAssertTypeEq<int, float>();
}