#include <iostream>
#include <ctime>

using namespace std;

class MyDate
{
    int year, month, day;
public:
    int isLeapYear(int year)
    {
        return (year % 4 == 0) && (year % 100 != 0) || (year % 400 ==0);
    }
    int isLeapYear()
    {
        return (year % 4 == 0) && (year % 100 != 0) || (year % 400 ==0);
    }
    bool isValid(int year,int month,int day)
    {
        if((month>=1 || month<=12) && (day<=31 || day>=1))
        {
            if(month==2 && day<=28)
            {
                return 1;
            }
            else if((month==4 || month==6 || month==9 || month==11) && (day<=30 || day>=1))
            {
                return 1;
            }
            else if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)&& (day<=31 || day>=1))
            {
                return 1;
            }
            else
            {
                return  0;
            }
        }
        else
        {
            return 0;
        }
    }
    MyDate(int y, int m, int d)
    {
        if (isValid(y,m,d) == 1)
        {
            cout << y << m << d << endl;
        }
        else
        {
            cout << "请输入有效日期" << endl;
        }
    }
    
    void print()
    {
        cout << year << "年" << month << "月" << day << "日"<< endl;
    }
};

int main()
{
    MyDate d1(2020, 3, 26);
    cout << d1.isLeapYear(2020)<<endl;
}