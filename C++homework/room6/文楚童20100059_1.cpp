/*定义并实现多项式类(polynomial)，实现多项式加,减,乘及求导运算,并用一个交互式主程序测试、使用该多项式类。
程序功能：
    显示如下菜单：
**************************************
s-设置当前多项式
l-调用assign_coef函数(设置多项式的某一项)
t-调用add_to_coef函数(将输入的系数累加到多项式的对应项中)
*c-调用clear函数(将当前多项式的各系数清零)
*v-显示当前多项式
a-显示所有多项式
d-对当前多项式求导并显示
e-计算当前多项式的值
+-显示A+B的和
-- 显示A-B的差
*-显示A*B的积
*q-退出
***************************************
本程序中共有三个多项式(a,b和c)，分别是主函数中定义的含三个多项式的对象数组中的元素：polynomial p[3];
多项式的加 ,减 ,乘运算针对的是p[0]和p[1]多项式，多项式的系数为double类型，
指数为在0到29之间的整数（提示：存放多项式的数组可定义成double coef[30]；），
本程序运行情况请参考test.exe文件。*/
#include <iostream>
using namespace std;

class polynomial{
    private:
        double coef[30] = {0};
        int count = 0;
        char a;
    public:
        void assign_coef(double,double,char);
        void print(char a);
        void swap(double &,double &);
        polynomial(char);           ///有参构造函数
        void circulate(char);
        void clear();
};

polynomial p[3] = {'a','b','c'};            //创建三个多项式对象，全局建立利于传参
void polynomial::clear()
{
    for(int i=0;i<15;i++)
        coef[i] = 0;
}

polynomial::polynomial(char b)
{
    coef[30] = 0;
    count = 0;
    polynomial::a = b;
}
void polynomial::swap(double & x,double & y)
{
    double temp = x;
    x = y;
    y = temp;
}
void print_all()
{
    p[0].print('a');
    p[1].print('b');
    p[2].print('c');
}

void polynomial::assign_coef(double x,double y,char a)             //设置单项值
{
    // switch(a){
    //     case 'a':cout << 'A :';break;
    //     case 'b':cout << 'B :';break;
    //     case 'c':cout << 'C :';break;
    // }
    if(count < 15)
    {
        for(int i = count;i>=0;i--)
        {
            if(i == 0)
            {
                coef[0] = x;
                coef[15] = y;
                polynomial::print(a);
            }
            if(coef[i-1]>x)
            {
                swap(coef[i-1],coef[i]);
                swap(coef[i+14],coef[i+15]);
            }
            else
            {
                coef[i] = x;
                coef[i+15] = y;
                polynomial::print(a);
                break;
            }
        }
        // for(int j = count + 15;j>=15;j--)
        // {
        //     if(j == 15)
        //         coef[j] = y;
        //     else if(coef[j-1]>y)
        //         swap(coef[j-1],coef[j]);
        //     else
        //         coef[j-1] = y;
        // }
    }
    count++;
}

void polynomial::print(char a)            //打印单项
{
    switch(a){
        case 'a':cout << 'A :';break;
        case 'b':cout << 'B :';break;
        case 'c':cout << 'C :';break;
    }
    for(int i = 0;i<=count;i++)
    {
        if(coef[i] == 0)
            continue;
        else 
        {
            cout << coef[i+15] <<"X ^" << (int)coef[i];
            if(i != count - 1)
                cout << " + ";
        }
        
    }
    // for(int i = 0;i<30;i++)
    //      cout << coef[i] << " ";
    cout << endl;
}
void polynomial::circulate(char a)
{
    char al;
    double x,y;
    while(1)
    {
        
    cin >> al;
    if(al == 'l')
    {
        cin >> x >> y;
        switch (a)
        {
        case 'a':
            p[0].assign_coef(x,y,'a');
            continue;
        case 'b':
            p[1].assign_coef(x,y,'b');
            break;
        case 'c':
            p[2].assign_coef(x,y,'c');
            break;
        default:
            break;
        }
    }
    if(al == 'q')
        return ;
    }
}


int main()
{
    char z,th;
    while(1)
    {
    cout << "---------------" << "The Commands" << "----------------" <<endl;
    cout << "s-设置当前多项式"<<"\n" << "l-调用assign_coef函数(设置多项式的某一项)"<<"\n"<<"t-调用add_to_coef函数(将输入的系数累加到多项式的对应项中)"<<"\n"<<"c-调用clear函数(将当前多项式的各系数清零)" << endl;
    cout << "v-显示当前多项式" << "\n" << "a-显示所有多项式" <<"\n" <<"d-对当前多项式求导并显示"<<"\n"<<"e-计算当前多项式的值"<<"\n" << "+-显示A+B的和" <<"\n" <<"-- 显示A-B的差"<<"\n" <<"*-显示A*B的积"<< "\n" << "*q-退出" << endl;
    cout <<"------------------------------------" << endl;
    cin >> z;
    if(z == 's')
    {
        cout <<"Enter the polynomial you want to work on:(a,b,c)";
        cin >> th;
        switch (th)
        {
        case 'a':
            p[0].circulate(th);
            break;
        case 'b':
            p[1].circulate(th);
            break;
        case 'c':
            p[2].circulate(th);
            break;
        }
    }
    if(z == 'q')
        return 0;
    }



    p[0].print('a');
    p[0].clear();
    cout << "*************";
    p[0].print('a');
    print_all();
    return 0;
}