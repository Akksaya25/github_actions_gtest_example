#include "gtest/gtest.h"
using testing::Types;

class ITempSensor{
    public:
    virtual int getOutsideTemp()=0;

};
class ModelATempSensor:public ITempSensor{
    public:
    int getOutsideTemp(){ return 23;}
};
class ModelBTempSensor:public ITempSensor{
    public:
    int getOutsideTemp(){ return 23;}
};
class AutoTempRegulator{
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegulator(ITempSensor* address):tempSensorPtr{address}{}
    void regulateTemp(){
        this->tempSensorPtr->getOutsideTemp();
    }
};
template <typename T>
ITempSensor* createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelATempSensor(); }

template <typename T>
class TempSensorFixture:public testing::Test{
    protected:
    TempSensorFixture():objUnderTest{createObject<T>()}{}
    //arrange
    ITempSensor* objUnderTest;

};
typedef Types<ModelATempSensor,ModelBTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations);

TEST_TEST(TempSensorFixture,GetTempTest){
    ASSERT_EQ(this->objUnderTest->getOutsideTemp(),23)
}
// class ModelBTempSensorFixture:public testing::Test{
//     protected:
//     //arrange
//     ModelBTempSensor objUnderTest;

// }
// TEST_F(ModelBTempSensorFixture,GetTempTest){
//     ASSERT_EQ(objUnderTest.getOutsideTemp(),23)
// }