#include "LinePoint.h"

// Point 构造实现
Point::Point(int px, int py) : x(px), y(py)
{
    cout << "Point构造 (" << x << "," << y << ")\n";
}

// Point 析构实现
Point::~Point()
{
    cout << "Point析构 (" << x << "," << y << ")\n";
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

Line::Line():start(),end()
{
    cout<<"无参构造"<<endl;
}

//================ Line 实现 ==================
Line::Line(const Point &p1, const Point &p2)
    : start(p1), end(p2)
{
    cout << "Line构造：两点构造线段\n";
}

Line::Line(int x1, int y1, int x2, int y2)
    : start(x1, y1), end(x2, y2)
{
    cout << "Line构造：四坐标构造线段\n";
}

Line::~Line()
{
    cout << "Line析构执行\n";
}

void Line::showLine() const
{
    cout << "线段起点(" << start.getX() << "," << start.getY()
         << ") 终点(" << end.getX() << "," << end.getY() << ")\n";
}