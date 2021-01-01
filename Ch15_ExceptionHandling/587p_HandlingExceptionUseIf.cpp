#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Input two numbers: ";
    cin >> num1 >> num2;

    if (num2 == 0)
        cout << "divisor can't be zero" << endl;
    else
    {
        cout << "quotient: " << num1 / num2 << endl;
        cout << "remainder: " << num1 % num2 << endl;
    }
    return 0;
}