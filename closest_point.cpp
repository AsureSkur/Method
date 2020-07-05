#include <cmath>  
#include <queue>  
#include <vector>  
#include<list>  
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iomanip>  
#include <iostream>  
#include <algorithm>  
using namespace std;

class Point
{
public:
    bool operator <(Point a)const
    {
        return x < a.x;
    }
    bool operator <=(Point a)const
    {
        return y <= a.y;
    }
    Point(double tx = 0, double ty = 0, int tp = 0)
    {
        x = tx;
        y = ty;
        p = tp;
    }
    friend double distance(const Point& u, const Point& v)
    {
        double dx = u.x - v.x;
        double dy = u.y - v.y;
        return sqrt(dx * dx + dy * dy);
    }
    friend double distX(const Point& u, const Point& v)
    {
        double dx = u.x - v.x;
        return fabs(dx);
    }
    friend double distY(const Point& u, const Point& v)
    {
        double dy = u.y - v.y;
        return fabs(dy);
    }
    void setVal(double tx, double ty)
    {
        x = tx;
        y = ty;
    }
private:
    int p;
    double x, y;
};
bool less_x(const Point& a, const Point& b)
{
    return a < b;
}
bool less_y(const Point& a, const Point& b)
{
    return a <= b;
}
double nearest(int l, int r);

vector<Point>bx;

int main()
{
    int N, i;
    double x, y;
    double ans;
    Point temp;
    while (1)
    {
        if (bx.size() != 0)
        {
            bx.clear();
        }
        scanf("%d", &N);
        getchar();
        if (N == 0)
        {
            break;
        }
        for (i = 0; i < N; i++)
        {
            scanf("%lf %lf", &x, &y);
            getchar();
            temp.setVal(x, y);
            bx.push_back(temp);
        }
        sort(bx.begin(), bx.end(), less_x);
        ans = nearest(0, N - 1);
        printf("%.2lf\n", ans / 2);
    }
}

double nearest(int l, int r)
{
    double d;

    if (l == r)
    {
        return 10e100;
    }
    else if (l + 1 == r)
    {
        return distance(bx[l], bx[r]);
    }
    int mid = (l + r) / 2;

    d = min(nearest(l, mid), nearest(mid + 1, r));

    vector<Point>by;
    int i, j;

    for (i = l; i <= r; i++)
    {
        if (distX(bx[i], bx[mid]) < d)
        {
            by.push_back(bx[i]);
        }
    }
    sort(by.begin(), by.end(), less_y);
    for (i = 0; i < by.size(); i++)
    {
        for (j = i + 1; j < by.size(); j++)
        {
            if (distY(by[i], by[j]) < d)
            {
                d = min(distance(by[i], by[j]), d);
            }
            else break;
        }
    }

    return d;
}