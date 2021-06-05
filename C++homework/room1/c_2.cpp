/*
程序说明：找出4名同学中做好事的人（其中一个人说了谎）
日期：2021年3月6日
姓名：文楚童
*/
#include <iostream>
using namespace std;
int main()
{
    char name[4] = {'A','B','C','D'};
    int i,count;
    for(i=0;i<4;i++)
    {
        count = 0;
        if(name[i] != 'A')
            count++;
        if(name[i] == 'C')
            count++;
        if(name[i] == 'D')
            count++;
        if(name[i] != 'D')
            count++;
        
        if(count == 3)
        {
            cout << "做好事的人是:" << name[i];
            break;
        }
    }
    return 0;
} 