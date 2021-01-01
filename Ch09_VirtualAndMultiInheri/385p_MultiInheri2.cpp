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
        // BaseOne�� BaseTwo�� ����� �̸��� �����ϹǷ�, � Ŭ������ �Լ��� �ҷ������� ��ȣ�ϴ�. ����, ��� Ŭ������ ���� �ҷ������� �������� �Ѵ�.
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