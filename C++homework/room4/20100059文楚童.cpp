/*
程序说明：为MyDate类增加功能，要求如下：
(1)为类增加有参和无参的构造函数，初始化为"合法"的日期(比如：2020年2月30日就不合法)
(2)增加一个成员函数:MyDate yesterday()，将当前对象日期设为昨天，并返回"昨天"的对象(MyDate yesterday()这里的MyDate是返回值的类型）
(3)完善set()函数，设置合法的日期
(4)求一个日期在指定天数之前/后的日期
(5)计算两个日期相距的天数
(6)在main函数中测试新增功能
姓名：文楚童
日期：2021-3-29
*/
#include<iostream>
#include<cmath>
using namespace std;
int is_leap_year(int);
int days(int,int);
class MyDate{
    public:
        int year,month,day;
        void set(int,int,int);
        void set(MyDate&);
        void print();
        void tomorrow();
        int equals(MyDate&);
        MyDate();                               //无参构造函数
        MyDate(int,int,int);                    //有参构造函数
        MyDate yesterday();                     //返回"昨天"的对象
};

int cal_days(int year,int month,int day)        //计算该日期在时间轴上是第几天，以0年0月0日为0点，公元前为负数
{
    int result=0;
    int k=0;
    for(int i=1;i<month;i++){
        result += days(year,i);
    }
    result += day;
    for(int i=0;i<year;i++){
        if(is_leap_year(i) == 1)
            k++;
    }
    result += (year+1)*365 + k;
    return result;
}
int dis_days(MyDate &t1,MyDate &t2)
{
    //计算两个日期在时间轴上的日期,以0年0日为起点，相减为天数差
    int day1;
    int day2;
    day1 = cal_days(t1.year,t1.month,t1.day);
    day2 = cal_days(t2.year,t2.month,t2.day);
    return fabs(day1-day2);
}
MyDate appointed_day(MyDate &t,int appo_days,int n)         //指点天数之前，后的日期,参数n为1则为指定日期后，否则为指定日期前
{
    if (n==1){
    //     if((t.day+appo_days)>days(t.year,t.month)){
    //         t.day = t.day+appo_days - days(t.year,t.month);
    //         t.month++;
    //         if(t.month > 12){
    //             t.month = 1;
    //             t.year++;
    //         }
    //     }
    //     else{
    //         t.day = t.day + appo_days;
    //     }
        for(int i=0;i<appo_days;i++)
            t.tomorrow();
    }
    else{
    //     if(t.day - appo_days <= 0){
    //         if((t.month - 1)<=0){
    //             t.month = 12;
    //             t.year--;
    //             t.day = days(t.year,t.month) + (t.day - appo_days);
    //         }
    //         else{
    //             t.month--;
    //             t.day = days(t.year,t.month) + (t.day - appo_days);
    //         }
    //     }
    //     else{
    //         t.day = t.day- appo_days;
    //     }
        for(int i=0;i<appo_days;i++)
            t.yesterday();
    }
    return t;
}
MyDate MyDate::yesterday()
{
    MyDate yest;
    MyDate::day--;
    if(day==0){
        month--;
        if(month==2){
            if(is_leap_year(year)==1)
                day = 29;
            else
                day = 28;
        }
        else
            day = days(year,month);
    }
    yest.year = year;
    yest.month = month;
    yest.day = day;
    return yest;
}
MyDate::MyDate()                        
{
    int year,month,day;
    year = rand()%2021+1;
    month = rand()%12+1;
    if (month == 2)              
    {
        if(is_leap_year(year)==1)       //是闰年
            day = rand()%29+1;
        else
            day = rand()%28+1;
    }
    else{
        int day_ = days(year,month);
        day = rand()%day_+1;
    }
    MyDate::set(year,month,day);
}

MyDate::MyDate(int year,int month,int day)
{
    MyDate::set(year,month,day);
}
void MyDate::set(int year,int month,int day){
   if(month == 2){
        if(is_leap_year(year)==1){
            if(day>days(year,month)){
                cout << "day error"<< endl;
            }
            else{
                MyDate::year = year;
                MyDate::month = month;
                MyDate::day = day;
            }
        }
    }
    else if(month>12){
            cout<<"month error"<<endl;
        }
    else{
        MyDate::year = year;
        MyDate::month = month;
        MyDate::day = day;
    } 
}

void MyDate::set(MyDate &t){

    if(t.month == 2){
        if(is_leap_year(t.year)==1){
            if(t.day>days(t.year,t.month)){
                cout << "day error"<< endl;
            }
            else{
                MyDate::year = t.year;
                MyDate::month = t.month;
                MyDate::day = t.day;
            }
        }
    }
    else if(t.month>12){
            cout<<"month error"<<endl;
        }
    else{
        MyDate::year = t.year;
        MyDate::month = t.month;
        MyDate::day = t.day;
    } 
}

void MyDate::print(){
    cout << MyDate::year<<"年"<<MyDate::month<<"月"<<MyDate::day<<"日";
}

int MyDate::equals(MyDate &t){
    if (MyDate::year == t.year)
        if(MyDate::month == t.month)
            if(MyDate::day == t.day)
                return 1;
    return 0;
}

int is_leap_year(int year)
{
    if (year % 4 == 0 && (year % 100!=0 || year % 400 == 0))
        return 1;
    return 0;
}
int days(int year,int month){
    int d = 1;
    int per_month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2)
        d = (is_leap_year(year)) ? 29:28;
    else
        d = per_month_day[month-1];
    return d;
}
void MyDate::tomorrow(){
    day++;
    if(day>days(year,month)){
        day = 1;
        month++;
        if(month > 12){
            month = 1;
            year++;
        }
    }
}
int main()
{
    int dist_days;
    srand((unsigned int)(time(NULL)));
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
    cout << endl;
    MyDate d3(2020,2,1);                //测试带参的构造函数
    MyDate d4;                          //测试不带参的构造函数
    MyDate d5(2019,3,1);                //测试yesterday函数
    MyDate d6(2020,3,1);    
    appointed_day(d6,5,0);              //测试指定天数之前/后的日期   
    dist_days = dis_days(d3,d6);                    //测试两天的距离       
    d5.yesterday();
    d3.print();                     
    cout << endl;
    d4.print();
    cout << endl;
    d5.print();
    cout<< endl;
    d6.print();
    cout << endl;
    cout<< dist_days << endl;

    return 0;
}