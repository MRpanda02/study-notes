/*
程序说明：在二维数组中找出最大值，并显示行和列。
日期：2021年3月6日
姓名：文楚童
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void max_array(int array[3][4],int &line,int &row,int &max)
{   
    max = array[0][0]; 
    int i,j;
    for(i = 0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(max<array[i][j])
            {
                max = array[i][j];
                line = i+1;
                row = j+1;
            }
        }
    }
}
int main()
{
    //int a[3][4] = {{1,2,3,4},{25,6,17,8},{9,10,11,12}};
    int a[3][4];
    int i,j;
    srand((unsigned int)(time(NULL)));
    for(i = 0;i<3;i++)
        for(j=0;j<4;j++)
        {
            a[i][j] = rand()%100;
        }
   for(i = 0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            cout << a[i][j]<<"      ";
        }
            cout<<"\n";
    }
             
    int hang,lie,max;
    max_array(a,hang,lie,max);
    cout << "maximum:"<<max<<"\n"<<"line:"<<hang<<"\n"<<"row:"<<lie;
    return 0;
}


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
        if(name[i] != 'A')     //分别列出符合4个人的条件
            count++;
        if(name[i] == 'C')
            count++;
        if(name[i] == 'D')
            count++;
        if(name[i] != 'D')
            count++;

        if(count == 3)     //其中符合任意三个人的条件即可

        {
            cout << "做好事的人是:" << name[i];
            break;
        }
    }
    return 0;
}
