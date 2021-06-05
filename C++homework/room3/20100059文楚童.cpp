/*
程序说明：本题要求大家根据main()函数对Point类的使用，写出Point类的定义
姓名：文楚童
日期：2021-3-18
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
    double Distance(const Point&);
    void set(double,double);
    void move(double,double);
    double getx();
    double gety();
};

double Point::Distance(const Point &t)
{
    double Dist = 0;
    Dist = sqrt(pow((Point::x - t.x),2)+pow((Point::y - t.y),2));
    return Dist;
}

void Point::move(double new_x,double new_y)
{
    Point::x = new_x;
    Point::y = new_y;
}

void Point::set(double x,double y)
{
    Point::x = x;
    Point::y = y;
}

double Point::getx()
{
    return Point::x;
}

double Point::gety()
{
    return Point::y;
}
int main()
{
    clock_t start,finish;
    start = clock();
    Point a,b,c;
    a.set(7.8,9.8);
    b.set(34.5,67.8);
    c=a;
     cout<<"a和b两点之距为："<<a.Distance(b)<<endl;
     cout<<"b和c两点之距为："<<b.Distance(c)<<endl;
     cout<<"a和c两点之距为："<<a.Distance(c)<<endl;
     c.move(26.7,58);                                       //将c点的坐标移动到参数所指定的位置
    cout<<"c("<<c.getx()<<","<<c.gety()<<")"<<endl;        //输出c点的坐标
    finish = clock();
    cout <<"Program executing time:" << finish-start <<"ms"<< endl;
    return 0;
}

/*
程序说明：本题要求根据main()函数对Point类的使用，写出Point类的定义
姓名：文楚童
日期：2021-3-18
*/
#include<iostream>
using namespace std;

struct MyDate
{
    int year,month,day;
    void set(int,int,int);
    void set(struct MyDate&);
    void print();
    void tomorrow();
    int equals(struct MyDate&);
};

void MyDate::set(int year,int month,int day)
{
    MyDate::year = year;
    MyDate::month = month;
    MyDate::day = day;
}

void MyDate::set(struct MyDate &t)
{
    MyDate::year = t.year;
    MyDate::month = t.month;
    MyDate::day = t.day;
}

void MyDate::print()
{
    cout << MyDate::year<<"年"<<MyDate::month<<"月"<<MyDate::day<<"日";
}

int MyDate::equals(struct MyDate &t)
{
    if (MyDate::year == t.year)
        if(MyDate::month == t.month)
            if(MyDate::day == t.day)
                return 1;
    return 0;
}

void MyDate::tomorrow()
{
    MyDate::day++;
        if(MyDate::month == 2)
        {
            if(MyDate::year%400 == 0 || (MyDate::year%4 == 0 && MyDate::year%100 != 0))
            {
                if (MyDate::day == 30)
                {
                    MyDate::month++;
                    MyDate::day = 1;
                }
            }
            else
            {
                if (MyDate::day == 30)
                {
                    MyDate::month++;
                    MyDate::day = 1;
                }
                
            }
        }
        else if (MyDate::month == 1||MyDate::month == 3||MyDate::month == 5||MyDate::month == 7||MyDate::month == 8||MyDate::month == 10)
        {
            if(MyDate::day == 32)
            {
                MyDate::month++;
                MyDate::day = 1;
            }
        }
        else if (MyDate::month == 12)
        {
            if(MyDate::day == 32)
            {
                MyDate::year++;
                MyDate::month = 1;
                MyDate::day = 1;
            }
        }
        else
        {
            if(MyDate::day == 31)
            {
                MyDate::month++;
                MyDate::day = 1;
            }
        }
}
int main()
{
	MyDate d1,d2;
	d1.set(2015,12,31);
	d2.set(d1);
	d1.print();
	cout << endl;
	d2.print();
	cout << endl;
	cout << "d1.equals(d2)?" << d1.equals(d2) << endl;
        //equals  判断d1和d2是否相等，当年，月，日全相等时返回1；否            
     //则返回0
	d1.print();
	cout << "的明天是:";
	d1.tomorrow();
	d1.print();
    return 0;
}