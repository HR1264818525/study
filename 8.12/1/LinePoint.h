#ifndef LINEPOINT_H
#define LINEPOINT_H

#include <iostream>
using namespace std;

// 点类声明
class Point
{
private:
    int x;
    int y;

public:
    Point(int px = 0, int py = 0);
    ~Point();

    int getX() const;
    int getY() const;
};

// 线段类声明，包含两个Point
class Line
{
private:
    Point start;
    Point end;

public:
    // 两种重载构造函数
    Line();
    Line(const Point &p1, const Point &p2);
    Line(int x1, int y1, int x2, int y2);

    ~Line();

    void showLine() const;
};

#endif