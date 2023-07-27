#include "gtest/gtest.h"
int divFun(intg numerator. int denominator)
{
    if(denominator==0 || denominator < 0){ return 0;}
    return numerator/denominator;
}
class DivFunTestSuite:public testing::TestWithParam<std::tuple<int,int,int>>{
    protected:
    DivFunTestSuite(){}
    ~DivFunTestSuite(){}

}
TEST(DivFunTestSuite,HandleValidInputs){
    int numerator=10;
    int denominator=5;
    int expectedValue=2;
    int actualValue=divFun(numerator,denominator);
    ASSERT_EQ(actualValue,expectedValue)

}
INSTANTIATE_TEST_SUITE_P(
    DivFunTestSuiteParameterExample,
    DivFunTestSuite,
    ::testing::Values(
        std::make_tuple(10,5,2),
        std::make_tuple(10,0,0),
        std::make_tuple(10,-5,0),
    )
)