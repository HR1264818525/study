#include "LinePoint.h"

int main()
{
    // 方式1：先定义点，再生成线段
    Point p1(2,3);
    Point p2(7,8);
    Line L1(p1,p2);
    L1.showLine();

    cout << "---------\n";

    // 方式2：直接传入四个坐标
    // Line L2(10,10,20,20);
    // L2.showLine();

    return 0;
}