#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

template <typename T>
void Swap(T& var1, T& var2)
{
    T tmp = var1;
    var1 = var2;
    var2 = tmp;
}

int main(void)
{
    Point p1(1, 2), p2(2, 1);
    Swap(p1, p2);
    p1.ShowPosition();
    p2.ShowPosition();
    return 0;
}