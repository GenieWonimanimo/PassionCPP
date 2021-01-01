#include <iostream>
using namespace std;

class BaseOne
{
public:
    void SimpleFunc() {cout << "BaseOne" << endl;}
};

class BaseTwo
{
public:
    void SimpleFunc() {cout << "BaseTwo" << endl;}
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
    void ComplexFunc()
    {
        // BaseOne과 BaseTwo의 멤버의 이름이 동일하므로, 어떤 클래스의 함수를 불러올지가 모호하다. 따라서, 어느 클래스의 것을 불러올지를 명시해줘야 한다.
        BaseOne::SimpleFunc();
        BaseTwo::SimpleFunc();
    }
};

int main(void)
{
    MultiDerived mdr;
    mdr.ComplexFunc();
    return 0;
}