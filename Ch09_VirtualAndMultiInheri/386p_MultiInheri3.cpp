#include <iostream>
using namespace std;

class Base
{
public:
    Base() {cout << "Base Constructor" << endl;}
    void SimpleFunc() {cout << "BaseOne" << endl;}
};

class MiddleDerivedOne : virtual public Base
{
public:
    MiddleDerivedOne() : Base()
    {
        cout << "MiddleDerivedOne Constructor" << endl;
    }
    void MiddleFuncOne()
    {
        SimpleFunc();
        cout << "MiddleDerivedOne" << endl;
    }
};

class MiddleDerivedTwo : virtual public Base
{
public:
    MiddleDerivedTwo() : Base()
    {
        cout << "MiddleDerivedTwo Constructor" << endl;
    }
    void MiddleFuncTwo()
    {
        SimpleFunc();
        cout << "MiddleDerivedTwo" << endl;
    }
};

// 가상으로 Base 클래스를 상속하는 두 클래스를 다음과 같이 다중 상속 시, Base 클래스의 멤버가 하나씩만 존재할 수 있다
class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
    LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
    {
        cout << "LastDerived Constructor" << endl;
    }
    void ComplexFunc()
    {
        MiddleFuncOne();
        MiddleFuncTwo();
        SimpleFunc();
    }
};

int main(void)
{
    cout << "객체생성 전 ....." << endl;
    LastDerived ldr;
    cout << "객체생성 후 ....." << endl;
    ldr.ComplexFunc();
    return 0;
}