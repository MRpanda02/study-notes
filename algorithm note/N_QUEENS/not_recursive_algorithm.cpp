#include <iostream>
#include <time.h>
using namespace std;
int cont = 0;
const int N=20;
int q[N];

void print(int total_lines)
{
    int b[N][N] = {0};
    int i,j;
    for(i=1;i <= total_lines;i++)
    {
        b[i][q[i]] = 1;   
    }
    for(i=1;i<=total_lines;i++)
    {
        for(j=1;j<=total_lines;j++)
        {
            if(b[i][j] == 1)
            {
                cout << " Q ";
            }
            else
            {
                cout << " X ";
            }
        }
        cout << "\n";
    }
}

int check(int line)
{
    int i;
    for(i = 1;i < line;i++)
    {
        if(q[i] == q[line] || abs(line - i) == abs(q[line] - q[i]))
        {
            return 0;
        }
    }
    return 1;
}

void check_m(int total_lines)
{
    int i;
    int line = 1;
    cout << "The possible configuration of N Queens are:\n";
    q[line] = 1;
    while(line > 0)                 //回退到line为0则退出算法
    {
       if(line <= total_lines && q[line] <= total_lines)
       {
           if(check(line)==0)               //如果line行q[line]列不能放queen
           {
               q[line]++;
           }
           else
           {
               line++;
               q[line] = 1;
           }
       }
       else
       {
        if(line>total_lines)
        {
            cont++;
            //cout << "#solution " << cont <<endl;
            //print(total_lines);
        }
        /*
        可能性1:若line>total_lines,由于要找出所有的可能性，所以要继续从下一列开始尝试
        可能性2:若q[line]>total_lines,从上一行的下一列继续进行尝试
        */
        line--;
        q[line]++;
       }
    }
}

int main()
{
    clock_t start,finish;
    int n;                              //输入待测皇后个数  
    cout << "Please input the number of Queen:";
    cin >> n;
    cout << "Using not recursive backtrack algorithm to solve the problem of " << n << "Queens.";
    start = clock();
    check_m(n);                         //开始计算
    finish = clock();
    cout << "Totally there are " << cont << " ways to solve.\n";
    cout << "Program execution time: " << (double)(finish-start) << "ms\n";
}