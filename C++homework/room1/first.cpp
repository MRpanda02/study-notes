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