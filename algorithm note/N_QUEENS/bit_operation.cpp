#include <iostream>
#include <time.h>
using namespace std;
//upperlim用来标记所有列都已经放置好了皇后
long cont = 0,upperlim = 1;

void test(long row,long ld,long rd,int total_lines)         //row,ld,rd中0代表可以放queen,1代表不可以放queen
{
    upperlim = (1<<total_lines) -1;                 //把前n位均设为1，表示所有的列都有皇后
    if (row != upperlim)                            //当有的列没有皇后时
    {
        long pos = upperlim & ~(row|ld|rd);         //把限制条件翻转，即1可以放queen,0不可以放queen
        while (pos)                             //0--皇后没有地方可放，回溯
        {
            /*
            -pos = (~pos) - 1  即负数的补码，作用是将原码中的最右边的1保留，其他全部翻转
            则 pos & -pos 的意思就是只保留原码中最右边的1，其他bit均置0
            */
            long p = pos & -pos;
            /*
            将原码的pos最右边的1的bit清零
            也就是为获取下一次的最右1做准备
            程序会回溯到这个位置继续试探
            */
            pos -=p;
            /*
            row+p:将当前列置1，表示记录这次皇后放置的列
            (ld+p)<<1:标记左边相邻的列不允许下一个皇后放置
            (rd+p)>>1:标记右边相邻的列不允许下一个皇后放置
            随着位移在每次选择列之前进行，原来N*N网格中某个位置已放置的皇后针对其对角线
            上产生的限制都被记录下来了
            */
            test(row+p,(ld+p)<<1,(rd+p)>>1,total_lines);    
        }        
    }
    else
    {
        cont++;
    }
}
int main(int argc,char *argv[])
{
    clock_t start,finish;
    long n;
    cout << "Please input the number of Queen:";
    cin >> n;
    cout << "Using not recursive backtrack algorithm to solve the problem of " << n << "Queens.";
    start = clock();
    test(0,0,0,n);                         //开始计算
    finish = clock();
    cout << "Totally there are " << cont << " ways to solve.\n";
    cout << "Program execution time: " << (double)(finish-start) << "ms\n";
    return 0;
}