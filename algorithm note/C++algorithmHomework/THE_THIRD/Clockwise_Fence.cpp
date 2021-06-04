/*
SAMPLE INPUT:

2
NESW
WSSSEENWNEESSENNNNWWWS

SAMPLE OUTPUT:

CW
CCW

The two fence paths with @ denoting the starting point:

*>*
^ v
@<*

  *<*<*<*
  v     ^
*<@     *
v       ^
* *>*>* *
v ^   v ^
* *<* * *
v   ^ v ^
*>*>* *>*
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

std::map <char,int> direction;
int main()
{
    int N,Count=0;
    cin >> N;
    Count = N;
    int X=0,Large_X = 0;
    char temp;
    string Info;
    char a[100];
    string* p;
    p = new string[N];
    while(N--){
        X = 0;
        Large_X = 0;
        cin >> Info;
        for(int i=0;i<Info.length();i++){
            a[i] = Info[i];
        }
        for(int i=0;i<Info.length();i++){               //通过判断栅栏最东边的一条边的方向即可确定
            if(a[i] == 'E'){                            //是顺时针还是逆时针
                X++;
            }
            if(a[i] == 'W'){
                X--;
            }
            if(X > Large_X){       //&& X >= Large_X   X > Last_X && 
                temp = a[i+1];
                Large_X = X;}}
    if(temp == 'N')
        p[Count-N-1] = "CCW";
    if(temp == 'S')
        p[Count-N-1] = "CW";
    }
    for(int i=0;i<Count;i++)
        cout << p[i] << endl;
    return 0;
}