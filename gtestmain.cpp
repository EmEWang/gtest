#include "gtest/gtest.h"
#include <iostream>
using namespace std;

// 调用时，RUN_ALL_TESTS（）宏：
//   1. 保存所有Google测试标记的状态。
//   2. 为第一个测试创建测试夹具对象。
//   3. 通过SetUp（）初始化它。
//   4. 在fixture对象上运行测试。
//   5. 通过TearDown（）清除夹具。
//   6. 删除夹具。
//   7. 恢复所有Google测试标志的状态。
//   8. 重复上述步骤进行下一个测试，直到所有测试运行结束。

// 定义测试后 使用RUN_ALL_TESTS（）运行它们，如果所有测试成功则返回0，否则返回1。
//   RUN_ALL_TESTS（）运行链接单元中的所有测试 - 它们可以来自不同的测试用例，甚至是不同的源文件。
// 重要：您不能忽略RUN_ALL_TESTS（）的返回值，否则gcc将给您一个编译器错误。
//   此设计的基本原理是自动测试服务基于其退出代码而不是其stdout / stderr输出来确定测试是否已通过;
//   因此您的main（）函数必须返回RUN_ALL_TESTS（）的值。
// 此外，如果测试夹具的构造函数在步骤2中产生致命故障，则步骤3-5没有意义，因此它们被跳过。
//   类似地，如果步骤3产生致命故障，则将跳过步骤4。
// 此外，您应该只调用一次RUN_ALL_TESTS（）。
//   多次调用它会与一些高级Google测试功能（例如线程安全死亡测试）冲突，因此不受支持

// :: testing :: InitGoogleTest（）函数解析Google测试标志的命令行，并删除所有已识别的标志。
//   这允许用户通过各种标志控制测试程序的行为，我们将在AdvancedGuide中介绍。
//   在调用RUN_ALL_TESTS（）之前必须调用此函数，否则标志将无法正确初始化。
int main(int argc,char* argv[])
{
        //testing::GTEST_FLAG(output) = "xml:"; //若要生成xml结果文件
        testing::InitGoogleTest(&argc,argv); //初始化
        return RUN_ALL_TESTS();                     //跑单元测试
        //return 0;
}