#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    if (num2 == 0)
        throw num2;
    cout << "quotient: " << num1 / num2 << endl;
    cout << "remainder: " << num1 % num2 << endl;
}

int main(void)
{
    int num1, num2;
    cout << "Input two numbers: ";
    cin >> num1 >> num2;

    try
    {
        Divide(num1, num2);
        cout << "finish dividing" << endl;
    }
    catch (int expn)
    {
        cout << "divisor can't be " << expn << endl;
    }
    return 0;
}