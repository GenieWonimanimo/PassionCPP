#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Input two numbers: ";
    cin >> num1 >> num2;

    try
    {
        if (num2 == 0)
            throw num2;
        cout << "quotient: " << num1 / num2 << endl;
        cout << "remainder:" << num1 % num2 << endl;
    }
    catch (int expn)
    {
        cout << "divisor can't be " << expn << endl;
    }
    cout << "end of main" << endl;
    return 0;
}