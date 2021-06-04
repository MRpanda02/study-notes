/*
Farmer John's pasture can be regarded as a large 2D grid of square "cells" (picture a huge chessboard). Initially, the pasture is empty.

John的放牧场可以被看作一个大的2D网格正方形“细胞们”(像一个大的象棋盘）。刚开始，这个牧场是空的。

Farmer John will add N(1≤N≤105) cows to the pasture one by one. The ith cow will occupy a cell (xi,yi) that is distinct from the cells occupied by all other cows (0≤xi,yi≤1000).

John将一个接一个的放入N(1≤N≤105)头牛，牛将占据一个格子(xi,yi),与其他牛所占据的格子不同

A cow is said to be "comfortable" if it is horizontally or vertically adjacent to exactly three other cows. Farmer John is interested in counting the comfortable cows on his farm. For each i in the range 1…N, output the total number of comfortable cows after the i th cow is added to the pasture.

如果一头牛在水平或垂直方向上恰好与另外三头牛相邻，那么这头牛就被称为“舒适”。农夫约翰对数他农场里舒服的牛很感兴趣。对范围1…N中的每i，输出第i头奶牛加入牧场后的舒适奶牛总数。


INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains a single integer N
. Each of the next N lines contains two space-separated integers, indicating the (x,y)coordinates of a cow's cell. It is guaranteed that all these cells are distinct.

第一行输入包括单个数字N
接下来的N行每一行包含两个用空格分隔的整数，表示牛的细胞的(x,y)坐标。保证所有这些细胞都是不同的。
OUTPUT FORMAT (print output to the terminal / stdout):
The ith line of output should contain the total number of comfortable cows after the first i cows are added to the pasture.

第i行输出应该包含第i头奶牛添加到牧场后舒适奶牛的总数。

SAMPLE INPUT:

8
0 1
1 0
1 1
1 2
2 1
2 2
3 1
3 2

SAMPLE OUTPUT:

0
0
0
1
0
0
1
2

After the first four cows are added, the cow at (1,1)

is comfortable.

After the first seven cows are added, the cow at (2,1)

is comfortable.

After the first eight cows are added, the cows at (2,1)
and (2,2)

are comfortable.

SCORING:
Test cases 1-4 satisfy N≤400.
Test cases 5-12 satisfy no additional constraints.
*/
#include <iostream>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool p[1000][1000];

bool ValidJudge(int x,int y)
{
    return x >=0 && x <=1000 && y >= 0 && y <=1000;
}

bool Comfortable(int x,int y)
{
    int NearCow = 0;
    if(p[x][y]){
    if(ValidJudge(x,y)){
    for(int i=0;i<4;i++){
        if(p[x+dx[i]][y+dy[i]])
            NearCow++;
    }}}
    if(NearCow == 3)
        return true;
    return false;
}
int main()
{
    int N,X,Y,ComforCows = 0;
    cin >> N;
    while(N--){
        cin >> X >> Y;
        if(ValidJudge(X,Y)){                                //再放入第i个之前先检查这个位置上下左右四个位置的
            for(int i=0;i<4;i++){                           //舒适的COW的数量，因为放入这头牛后舒适的COW必不再舒适
                if(Comfortable(X+dx[i],Y+dy[i]))            //所以先剪掉舒适的COW
                    ComforCows--;
            }
        p[X][Y] = true;
        for(int i=0;i<4;i++){                               //放入COW之后，再检查舒适的COW
            if(Comfortable(X+dx[i],Y+dy[i]))                //加入到现阶段舒适的COW的变量里
                ComforCows++;}                              //为我们所求的数
        if(Comfortable(X,Y))
            ComforCows++;
        
    }
    cout << ComforCows << endl;
    }
    return 0;
}