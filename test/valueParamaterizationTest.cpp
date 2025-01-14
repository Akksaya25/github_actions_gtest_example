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

};
TEST_P(DivFuncTestSuite, HandleInputs){
    int numerator = std::get<0>(GetParam());
    int denominator = std::get<1>(GetParam());
    int expectedValue = std::get<2>(GetParam());
    int actualValue = divFunc(numerator, denominator);
    ASSERT_EQ(actualValue, expectedValue);

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