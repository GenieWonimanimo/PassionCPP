#include <iostream>
#include <string>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    { }
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }
    void SimpleFunc(const SoSimple& ref)
    {
        cout << "SimpleFunc: " << num << endl;
        cout << "SimpleFunc2: " << ref.num << endl;
    }
    void SimpleFunc() const
    {
        cout << "const SimpleFunc: " << num << endl;
    }
};

void YourFunc(const SoSimple &obj)
{
    obj.SimpleFunc();
}

int main(void)
{
    char a[] = "abcd";
    string b = a;
    string c = "abcd";
    cout << a << endl << b << endl;
    for (char d : a)
    {
        if (d == '\0')
            cout << "NULL1" << endl;
    }
    for (char d : b)
    {
        if (d == '\0')
            cout << "NULL2" << endl;
    }
    for (char d : c)
    {
        if (d == '\0')
            cout << "NULL3" << endl;
    }
    return 0;
}