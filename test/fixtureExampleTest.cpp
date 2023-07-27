#include "gtest/gtest.h"

class C{};

class B{

    C* ptr;

    public:

    B(C* addressOfObject): ptr{addressOfObject}{




    }

};




class A{

    B* ptr;

    public:

    A(B* addressOfObject): ptr{addressOfObject}{




    }

    bool  operation(){

        return true;

    }

};


class TestFixtureTestSuite:public testing: :Test{
    protected:
    A* aPtr;
    B* bPtr;
    C* cPtr;
    TestFixtureTestSuite(){
        //initialization
    }
    TestFixtureTestSuite(){
        //Releasing the Resource
    }
    void SetUp(){
        //Arrange
        this->cPtr-new C();
        this->bPtr-new B(cPtr);
        this->aPtr-new A(bPtr);
    }
    void TearDown(){
        //delete resource
        delete cPtr;
        delete bPtr;
        delete aPtr;
    }
}



 TEST(TestFixtureTestSuite,OperationTrueTest){

//     //Arrange

//     C cObj;

//     B bObj(&cObj);

//     A obj(&bObj);

//     //Act and Assert

     ASSERT_TRUE(aPtr->operation());

 }

TEST(TestFixtureTestSuite,OperationFalseTest){

    //Arrange

    //C cObj;

    //B bObj(&cObj);

    //A obj(&bObj);

    //Act and Assert

    ASSERT_FALSE(aPtr->operation());





}