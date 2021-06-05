#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;
};

class Line
{
private:
    int x, y;
    double color;
    Point p1,p2;
public:
    double get(double _x, double _y)
    {
        _x = x;
        _y = y;
    }
    double Distance(const Point &t)
    {
        double dis;
        dis = sqrt(pow(Line::p1. - t.x, 2) + pow(Line::p2.y - t.y, 2));
        return dis;
    }
    static int num(Line &n)
    {
        double a;
        a = Line::num(Line &);
    }

    double p1(double _x, double _y)
    {
        _x = x;
        _y = y;
    }
    double p2(double _x, double _y)
    {
        _x = x;
        _y = y;
    }
    
    
    
};


int main()
{
    Line b, c;
    b.p1(4, 5);
    c.p2(5, 6);
    cout << b.get() << endl
    cout << c.get() << endl
    cout << b.Distance(c) << endl
    cout << color << endl
    cout << num << endl
    
    return 0;
}