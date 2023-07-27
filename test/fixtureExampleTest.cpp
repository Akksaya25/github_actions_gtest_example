#include <gtest/gtest.h>
class C{};
class B{
       C* ptr;
    public:
    B(C* addressOfObject): ptr(addressOfObject){
        
    }
};
class A{
    B* ptr;
    public:
    A(B* addressOfObject): ptr(addressOfObject){

    }
    bool operation(){
        return true;
    }
};

TEST("TestFixtureTestSuite","OperationTest"){
    C cobj;
    B bobj(&cobj);
    A obj(&bobj);
    //Act and Assert
    Assert_TRUE(obj.operation());
}
TEST(TestFixtureTestSuite,OperationTest){
    C cobj;
    B bobj(&cobj);
    A obj(&bobj);
    //Act and Assert
    Assert_FALSE(obj.operation());
}