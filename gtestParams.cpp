#include "gtest/gtest.h"
#include <vector>

#include "samplemy2.h"

using namespace std;


// 旧的方案
// TEST(ISOdd, test2)
// {
//     EXPECT_TRUE(Odd(3));
//     EXPECT_TRUE(Odd(5));
//     EXPECT_TRUE(Odd(11));
//     EXPECT_TRUE(Odd(23));
// }

// 使用参数化后的方案
// 1. 告诉gtest你的参数类型是什么
// 你必须添加一个类，继承testing::TestWithParam<T>，其中T就是你需要参数化的参数类型，
//   比如上面的例子，我需要参数化一个int型的参数
class IsOddTest : public::testing::TestWithParam<int>
{
};

// 2. 告诉gtest你拿到参数的值后，具体做些什么样的测试
// 这里，我们要使用一个新的宏（嗯，挺兴奋的）：TEST_P，关于这个"P"的含义，
//   Google给出的答案非常幽默，就是说你可以理解为”parameterized" 或者 "pattern"。
//   我更倾向于 ”parameterized"的解释，呵呵。在TEST_P宏里，使用GetParam()获取当前的参数的具体值。
TEST_P(IsOddTest, test3)
{
    int n =  GetParam();
    EXPECT_TRUE(Odd(n));
}

// 3. 告诉gtest你想要测试的参数范围是什么
//  使用INSTANTIATE_TEST_CASE_P这宏来告诉gtest你要测试的参数范围：
INSTANTIATE_TEST_CASE_P(IsOddTestParams, IsOddTest, testing::Values(3, 5, 11, 23));
// 第一个参数是测试案例的前缀，可以任意取。
// 第二个参数是测试案例的名称，需要和之前定义的参数化的类的名称相同，如：IsPrimeParamTest
// 第三个参数是可以理解为参数生成器，上面的例子使用test::Values表示使用括号内的参数。
//   Google提供了一系列的参数生成的函数：
// Range(begin, end[, step])	范围在begin~end之间，步长为step，不包括end
// Values(v1, v2, ..., vN)	v1,v2到vN的值
// ValuesIn(container) and ValuesIn(begin, end)	从一个C类型的数组或是STL容器，或是迭代器中取值
// Bool()	取false 和 true 两个值
// Combine(g1, g2, ..., gN)
// 这个比较强悍，它将g1,g2,...gN进行排列组合，g1,g2,...gN本身是一个参数生成器，每次分别从g1,g2,..gN中各取出一个值，
//   组合成一个元组(Tuple)作为一个参数。
// 说明：这个功能只在提供了<tr1/tuple>头的系统中有效。gtest会自动去判断是否支持tr/tuple，如果你的系统确实支持，
//   而gtest判断错误的话，你可以重新定义宏GTEST_HAS_TR1_TUPLE=1。
// 命名规则大概为：prefix/test_case_name.test.name/index


struct params_add
{
    int a;
    int b;
};
class IsAddTest : public::testing::TestWithParam<params_add>
{
    // typedef vector<struct params_add> vct_param_add;
    // vct_param_add vpa;
    // vpa.size();
};
TEST_P(IsAddTest, test3)
{
    struct params_add n =  GetParam();
    EXPECT_EQ(20, Add(n.a, n.b));
}

struct params_add nn   = {13,17};
struct params_add nnn[]= {{13,7},{1,19},{2,18}};


// vct_param_add.push_back(nnn);
// INSTANTIATE_TEST_CASE_P(IsAddTestParams, IsAddTest, testing::Values(nn));
INSTANTIATE_TEST_CASE_P(IsAddTestParams, IsAddTest, testing::ValuesIn(nnn));
