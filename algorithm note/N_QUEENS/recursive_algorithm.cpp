#include <iostream>
#include <time.h>
using namespace std;
const int N=20;                 //最大皇后数为20
int q[N];                       //i为皇后所在为行数，q[i]为皇后所在的列数
int cont = 0;                  //统计解得的个数

void print(int total_lines)
{
    cont++;
    int i,j;
    cout <<"solution " << cont <<endl;
    for (i = 1; i <= total_lines; i++){
        for(j = 1;j <= total_lines;j++){
            if (q[i]!=j){
                cout << " X ";
            }
            else{
                cout << " Q ";
            }
        }
        cout << "\n";
    }
    
}

int find(int line,int row)
{
    int j = 1;
    while (j<line){
        //第j行的皇后是否在row列且(j,q[j])与(line,row)是否在对角线处
        if (q[j] == row || abs(j - line)==abs(q[j] - row)){
            return 0;
        }
        j++;
    }
    return 1;
}
void place(int line,int total_lines)
{
    if(line > total_lines){
        //print(total_lines);
        cont++;   
    }
    else{
        for(int j=1;j<=total_lines;j++){
            if(find(line,j))
            {
                q[line] = j;
                place(line+1,total_lines);              //进行递归，直到line>total_lines
            }
        }
    }
}
int main()
{
    clock_t start,finish;
    int num;                    //输入皇后的个数
    cout << "Please input the number of Queen:";
    cin >> num;
    cout << "Using recursive backtrack algorithm to solve the problem of "<< num <<" Queens\n";
    start = clock();
    place(1,num);               //从第一行开始进行判断
    finish = clock();
    cout << "Totally there are "<< cont <<" ways to solve\n";
    cout << "Program execution time: " << (double)(finish - start) << "ms\n";
    return 0;
}