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
    Point& operator+=(const Point& pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;
        return *this;
    }
    Point& operator-=(const Point& pos)
    {
        xpos -= pos.xpos;
        ypos -= pos.ypos;
        return *this;
    }
    friend Point operator+(const Point& pos1, const Point& pos2);
    friend Point operator-(const Point& pos1, const Point& pos2);
    friend bool operator==(const Point& pos1, const Point& pos2);
};


Point operator+(const Point& pos1, const Point& pos2)
{
    return Point(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}
Point operator-(const Point& pos1, const Point& pos2)
{
    return Point(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
}
bool operator==(const Point& pos1, const Point& pos2)
{
    return ( (pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos) );
}
bool operator!=(const Point& pos1, const Point& pos2)
{
    return !(pos1 == pos2);
}

int main(void)
{   
    Point pos1(3, 4);
    Point pos2(10, 20);
    pos1.ShowPosition();
    pos2.ShowPosition();

    Point pos3(3, 4);
    if (pos3 == pos1) cout << "same" << endl;
    if (pos3 != pos2) cout << "different" << endl;
    return 0;
}