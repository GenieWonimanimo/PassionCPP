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

class BoundCheck2DIntArray
{
private:
    BoundCheckIntArray** arr;
    int row;
    BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) { } // prevent
    BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {return *this;}
public:
    BoundCheck2DIntArray(int row, int col)
        : row(row)
    {
        arr = new BoundCheckIntArray*[row];
        for (int i = 0; i < row; i++)
            arr[i] = new BoundCheckIntArray(col);
    }
    BoundCheckIntArray& operator[] (int rowIdx)
    {
        if (rowIdx < 0 || rowIdx >= row)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return *(arr[rowIdx]);
    }
    /*
    it cause error!
    in the process of return,
    this func tries to assign *(arr[rowIdx]) to temporary object
    BoundCheckIntArray operator[] (int rowIdx) const
    {
        if (rowIdx < 0 || rowIdx >= row)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return *(arr[rowIdx]);
    }
    */
    int GetRow() const {return row;}
    ~BoundCheck2DIntArray()
    {
        for (int i = 0; i < row; i++)
            delete arr[i];
        delete []arr;
    }
};

int main(void)
{
    BoundCheck2DIntArray arr2d(3, 4);
    for (int n = 0; n < 3; n++)
        for (int m = 0; m < 4; m++)
            arr2d[n][m] = n + m;
    
    for (int n = 0; n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
            cout << arr2d[n][m] << " ";
        cout << endl;
    }

    return 0;
}