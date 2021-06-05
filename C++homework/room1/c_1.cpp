/*
程序说明：输入一个正整数，输出次正整数中每个数字的个数
日期：2021年3月6日
姓名：文楚童
 */
#include <iostream>
using namespace std;

int *calc_number(int num)
{
    int i;
    int *p = new int[10];
    for(i=0;i<10;i++)
        p[i] = 0;
    for(i=0;;i++)
    {
        p[num%10]++;
        num /= 10;
        if(num<=0)
            break;
    }
    return p;
}
int main()
{
    int num,i,*p;
    cin >> num;
    p = calc_number(num);
    for(i=0;i<10;i++)
    {
        cout << "数字"<<i<<"的个数:"<<p[i]<<"\n";
    }
    delete(p);
    return 0;
}