/*
熄灯问题思路:应用枚举的方法，局限条件是从第一行开始进行穷举，有64种排列方法，第一行的排列方式和开关方案决定了第二行的开关方案，以此类推。
*/
#include <iostream>
#include <time.h>
using namespace std;
int count = 1;
void SetBit(char &orilight,int line,int k)
{
    if(k)
        orilight |= (1 << line);                    //把第line位变为1  
    // else
    //     orilight &= ~(1 << line);
}

void show(char *orilight)
{
    cout << "#PUZZLE" << ::count++ << endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout << (*(orilight+i) >> j &1) << " ";
        }
        cout <<"\n";
    }
}

void Flip(char &lights,int j)
{
    lights ^= (1 << j);                     //对第j位进行翻转，^按位异或运算符，两数相同时为0，不同为1
}


int GetBit(int switchs,int i)
{
    return (switchs >> i) & 1;              //返回第i位的数
}
int main()
{
    clock_t start,finish;
    char oriLights[5];                  //初始状态的灯
    char lights[5];                     //不断变换的灯
    char result[5];                     //点的灯为1，不点则为0
    char switchs;                       //每一行的开关方案
    memset(oriLights,0,sizeof(oriLights));
    start = clock();
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            int k;
            cin >> k;
            SetBit(oriLights[i],j,k);
        }
    }

    for(int n=0;n<64;n++){
        memcpy(lights,oriLights,sizeof(oriLights));
        switchs = n;                    //穷举第一行的所有开关方案
        for(int i=0;i<5;i++){
            result[i] = switchs;
            for(int j=0;j<6;j++){
                if(GetBit(switchs,j)){            //如果在开关方案里等于1,则熄灭    
                    if (j>0)
                        Flip(lights[i],j-1);
                    if (j<5)
                        Flip(lights[i],j+1);
                    Flip(lights[i],j);
                }
            }
            if(i<4)
                lights[i+1] ^= switchs;             //表示这一行的开关操作影响下一行的灯，即开关方案的1处，下一行的同列均取反
            switchs = lights[i];                    //把这一行的开灯状态当成下一行的开关方案，即在下一行关掉这一行所有的灯
        }                                           //编程时疑惑之处在于，为什么没有对上一行取反？
//因为没有必要特意去表示对上一行取反，对下一行进行取反操作是因为它们会影响下一行的开关方案，对下一行进行取反也是为了及时反应这一行的开关后的影响，而对上一行的取反操作并不会有实质性的作用
        if(lights[4] == 0)                          //如果最后一行全熄灭，则输出，并退出循环
        {
            show(result);
            break;
        }
    }
    finish = clock();
    cout <<"Program executing time:" << finish-start <<"ms"<< endl;
    return 0;
}