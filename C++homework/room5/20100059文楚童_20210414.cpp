#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
        double x,y;
    public:
        Point();                //无参构造函数
        Point(double,double);   //有参构造函数
        Point(const Point &);
        void copy(double x,double y);
        void print();
        double getx();
        double gety();
};

class Line{
    private:
        static int num;             //程序中创建的线段对象的个数
        Point p1,p2;                //线段的起点和终点
        int color;                  //线段的颜色
    public:
        double length(Point&,Point&);
        Line();                         //无参构造函数
        Line(int,Point&,Point&,int);    //有参构造函数，参数分别为线段对象的个数，线段的起点，线段的终点，线段的颜色
        Line(Line &);
        void print();
        void copy(int,Point&,Point&,int);
};
int Line::num = 0;                  //编译出错，静态成员出错
void Point::copy(double x,double y)
{
    x = 0.0;
    y = 0.0;
}

void Line::copy(int x,Point&t1,Point&t2,int y)
{
    Line::num = x;
    Line::color = y;
    Line::p1 = t1;
    Line::p2 = t2;
}
Point::Point(const Point & t)
{
    Point::copy(t.x,t.y);
}

Line::Line(Line & t)
{
    Line::copy(t.num,t.p1,t.p2,t.color);
}
double Point::getx()
{
    return Point::x;
}
double Point::gety()
{
    return Point::y;
}


void Line::print()
{
    cout << "color :" << Line::color << endl;
    Line::p1.print();
    Line::p2.print();
    cout << "line number :" << Line::num << endl;
    cout << "line length :" << Line::length(Line::p1,Line::p2) << endl;
}

void Point::print()
{
    cout << "(" <<Point::x << "," << Point::y << ")" << endl;
}
Point::Point()
{
    Point::x = 0.0;
    Point::y = 0.0;
}

Point::Point(double a,double b)
{
    Point::x = a;
    Point::y = b;
}

Line::Line()
{
    Line::color = 0;
    Line::p1.copy(0.0,0.0);
    Line::p2.copy(0.0,0.0);
    Line::num ++;
    
}

Line::Line(int col,Point &t1,Point &t2,int num)
{
    Line::color = col;
    Line::p1 = t1;
    Line::p2 = t2;
    Line::num ++;
    
}

double Line::length(Point &p1,Point &p2)
{
    double len = sqrt(pow(p1.getx() - p2.getx(),2) + pow(p1.gety() - p2.gety(),2));
    return len;
}
int main()
{
    cout << "Point类构造函数测试"<<endl;
    Point p1;               //测试无参构造函数
    Point p2(1.0,2.0);
    p1.print();
    p2.print();
    cout << "Line类构造函数构造"<<endl;
    Line line1;
    Line line2(1,p1,p2,10);
    line1.print();
    line2.print();
    cout << "Point类复制构造函数"<<endl;
    Point p3(p2);
    p3.print();
    cout << "Line类复制构造函数"<<endl; 
    Line line3(line2);
    line3.print();
    return 0;
}