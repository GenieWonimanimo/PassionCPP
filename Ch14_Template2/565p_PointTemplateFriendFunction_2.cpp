/*
modyfied of prev code
*/

#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
    T GetX() const {return xpos;}
    T GetY() const {return ypos;}
};

// you cant use general function template as a friend function of class
template <typename T>
Point<T> operator+(const Point<T>& pos1, const Point<T>& pos2)
{
    return Point<T>(pos1.GetX() + pos2.GetX(), pos1.GetY() + pos2.GetY());
}
template <typename T>
ostream& operator<<(ostream& os, const Point<T>& pos)
{
    os << "[" << pos.GetX() << ", " << pos.GetY() << "]" << endl;
    return os;
}

int main(void)
{
    Point<int> pos1(2, 4);
    Point<int> pos2(4, 8);
    Point<int> pos3 = pos1 + pos2;
    cout << pos1 << pos2 << pos3;

    Point<double> pos4(1.1, 2.2);
    Point<double> pos5(3.3, 4.4);
    Point<double> pos6 = pos4 + pos5;
    cout << pos4 << pos5 << pos6;
    return 0;
}