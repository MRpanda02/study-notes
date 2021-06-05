/*
程序说明：对两个由随机数组成的从小到大的有序数列，进行合并生成一个从小到大的有序数列并输出
日期：2021年3月12日
姓名：文楚童
*/
#include <iostream>
#include <cmath>
using namespace std;

int *random(int n,int max)
{
    int *rand_array;
    rand_array = new int[n];
    for (int i = 0; i < n; i++)
        rand_array[i] = rand()%max;
    return rand_array;
}

void output_array(int a[],int num)
{   
    for(int i = 0;i<num;i++)
    {
        cout << a[i] <<" ";
        if (i>0 && (i+1)%5 == 0)
            cout<< endl;
    }
    cout<< "*******************"<<endl;
}

/*
函数说明：把数组里的数分成有序部分和无序部分，把无序部分最左端的带排序元素和有序部分进行排列
*/
void sort(int *a,int num)
{
    int i;
    int temp;
    for(i = 1;i<num;i++)
    {
        int j = i;
        while(j > 0)
        {
            if(a[j]<a[j-1])
            {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                j--;
            }
            else
                break;
        }
    }
}
/*
函数说明：数组x,y的第0元素之间进行比较，小的占据0位，
小的元素所属于的数列的第1元素继续与另一个数组的0元素进行比较，以此类推
*/
int *merge(int x[],int y[],int m,int n)         
{
    // int *z;
    // int k = 0,j = 0;
    // z = new int[m+n];
    // for(int i = 0;k < m+n;)
    // {
    //     if (j > n-1)
    //         break;
    //     if(x[i] > y[j])
    //     {
    //         z[k] = y[j];
    //         k++;
    //         j++;
    //     }
    //     else
    //     {
    //         z[k] = x[i];
    //         k++;
    //         i++;
    //     }
    //     while(j == n && k < m+n)
    //     {
    //         z[k] = x[i];
    //         ++i;
    //         ++k;
    //     }
    //     while(i == m && k < m+n)
    //     {
    //         z[k] = y[j];
    //         j++;
    //         k++;
    //     }
    // }
    // return z;
    int *p;
    p = new int[m+n];
    int j=0,k=0,i=0;
    while(j<m&&k<n)
    {
        if (x[j]<y[k])
        {
            p[i++]=x[j++];
        }
        else
        {
            p[i++]=y[k++];
        }
        while (j<m)
        {
            p[i++]=x[j++];
        }
        while (k<n)
        {
            p[i++]=y[k++];
        }
    }
    return p;
}
int main()
{
    srand((unsigned int)(time(NULL)));
    int *x,m = 10,i,*y,*z,n = 20;
    x = random(m,100);              //随机生成最大值为100的m个数值
    y = random(n,100);

    sort(x,m);                      //分别对两个随机数进行排列
    sort(y,n);

    output_array(x,m);              //输出所生成的随机数列
    output_array(y,n);

    z = merge(x,y,m,n);             //对两个数组进行排序

    output_array(z,m+n);

    delete []x;
    delete []y;
    delete []z;
}