#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool is_zero(double x) {
	x = x > 0 ? x : -x;
	return x < 10e-8;
}

struct point
{
    double x, y;
} p1, p2, p3, p4;

bool Parallel(point u1, point u2, point v1, point v2)
{
    return is_zero((u1.x-u2.x)*(v1.y-v2.y)-(v1.x-v2.x)*(u1.y-u2.y));
}

double cross(point p1, point p2, point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
}

double Dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double Dis_to_line(point p, point l1, point l2)
{
    return fabs(cross(p, l1, l2)) / Dis(l1, l2);
}

point touchpoint(point u1, point u2, point v1, point v2)
{
    point ret = u1;
    double t = ((u1.x-v1.x)*(v1.y-v2.y) - (u1.y-v1.y)*(v1.x-v2.x)) / ((u1.x-u2.x)*(v1.y-v2.y) - (u1.y-u2.y)*(v1.x-v2.x));
    ret.x += (u2.x-u1.x) * t;
    ret.y += (u2.y-u1.y) * t;
    return ret;
}

int main()
{
    int n, x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--)
    {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        p1.x = x1, p1.y = y1;
        p2.x = x2, p2.y = y2;
        p3.x = x3, p3.y = y3;
        p4.x = x4, p4.y = y4;
        if(Parallel(p1, p2, p3, p4))
        {
            if(is_zero(Dis_to_line(p2, p3, p4)))
                printf("LINE\n");
            else
                printf("NONE\n");
        }
        else
        {
            point p = touchpoint(p1, p2, p3, p4);
            printf("POINT %.2f %.2f\n", p.x, p.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}

