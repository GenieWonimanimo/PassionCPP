#include <iostream>
using namespace std;

class SoSimple // Polymorphic class cuz ShowSimpleInfo is virtual func
{
public:
    virtual void ShowSimpleInfo()
    {
        cout << "SoSimple Base Class" << endl;
    }
};

class SoComplex : public SoSimple
{
public:
    virtual void ShowSimpleInfo() override // also virtual class
    {
        cout << "SoComplex Derived Class" << endl;
    }
};

int main(void)
{
    SoSimple* simPtr = new SoSimple;
    SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
    if (comPtr == NULL)
        cout << "Fail to casting" << endl;
    else
        comPtr->ShowSimpleInfo();    
    return 0;
}