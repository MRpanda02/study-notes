#include <iostream>
#include <cmath> 
using namespace std;
class MyDate
{public:
 int year,month,day;
void set(int y,int m,int d)
{year=y; month=m;day=d;}


void set(MyDate d)
{year=d.year; month=d.month; day=d.day;}

void print()
{cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;}

int equals(MyDate d)
{return year==d.year&&month==d.month&&day==d.day;}

int is_leap_year()
{return year%4==0&&year%100!=0||year%400==0;}

int days()
{int days_permonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int d;
if (month==2)
d=is_leap_year ()? 29 : 28;
else d=days_permonth[month-1];
return d;}

void tomorrow()
{day++;
if(day>days())
{day=1;
month++;
if(month>12)
{month=1;
year++;}
}
}

void yesterday()
{day--;
if(day==0)
{month--;day=days();}

if(month==0)
{
month=12;
year--;
}
}

};


int main()
{MyDate d1,d2;
d1.set(2015,11,21);
// d2.set(d1);
// d1.print();
// cout<<endl;
// d2.print();
// cout<<endl;
// cout<<"d1.equals(d2)?"<<d1.equals(d2)<<endl;
// d1.print();
// cout<<"的明天是：";
// d1.tomorrow();
// d1.print();
// cout<<"的昨天是：";
// d1.yesterday();

d1.yesterday();
d1.print();
return 0;
}