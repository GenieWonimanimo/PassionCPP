#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int* arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& arr) { } // prevent
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { return *this; } // prevent
public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[] (int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int operator[] (int idx) const // overload by const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const {return arrlen;}
    ~BoundCheckIntArray()
    {
        delete []arr;
    }
};

void ShowAllData(const BoundCheckIntArray& ref)
{
    int len = ref.GetArrLen();
    for (int idx = 0; idx < len; idx++)
        cout << ref[idx] << endl; // it cause error, operator[] is not a const
}

int main(void)
{
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11; // arr.operator[](i)
    ShowAllData(arr);
    return 0;
}