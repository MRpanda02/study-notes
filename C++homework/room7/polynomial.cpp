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
#include<iostream>
using namespace std;
class Polynomial{
private:
     double coef[30];
public:
    Polynomial();
    void assign_coef(double coefficient,unsigned int exponent);
    void add_to_coef(double amount,unsigned int exponent);
    void clear();
    void print();
    void derivative();
    int value();
    void sum(Polynomial &p1, Polynomial &p2);
    void differ(Polynomial &p1, Polynomial &p2);
    void multiply(Polynomial &p1, Polynomial &p2);
};
Polynomial::Polynomial()
{
    for(int i=0;i<30;i++)
    {
        coef[i]=0;
    }
}
void Polynomial::assign_coef(double coefficient,unsigned int exponent)
{
    coef[exponent]=coefficient;
}
void Polynomial::add_to_coef(double amount,unsigned int exponent)
{
    coef[exponent]=amount;

}
void Polynomial::clear()
{
     for(int i=0;i<30;i++)
     {
         if(coef[i]!=0)
         {
             coef[i]=0;
         }
     }
}
void Polynomial::print()
{
    for(int i=0;i<30;i++)
    {
        if(coef[i]!=0)
        {
             cout<<coef[i]<<"X^"<<i<<endl;
        }
    }
}
void Polynomial::derivative()
{
    int i;
    for(i=0;i<30;i++)
    {
         if(coef[i]!=0)
         {
             int a=i-1;coef[a]=coef[i]*i;
         }
    }
   cout<<coef[i]<<endl;
}
int Polynomial::value()
{
    return 1;
}
void Polynomial::sum(Polynomial &p1, Polynomial &p2)
{
    int i; double s[30];
    for(i=0;i<30;i++)
    {
        s[i]=p1.coef[i]+p2.coef[i];
         if(s[i]==0)
		    {continue;}
	     else
        {cout<<s[i]<<"x^"<<i<<"+";}
	}
	cout<<endl;
}
void Polynomial::differ(Polynomial &p1, Polynomial &p2)
{
      int i; double s[30];
    for(i=0;i<30;i++)
    {
        s[i]=p1.coef[i]-p2.coef[i];
         if(s[i]==0)
		    {continue;}
	     else
        {cout<<s[i]<<"x^"<<i<<"-";}
	}
	cout<<endl;
}
void Polynomial::multiply(Polynomial &p1, Polynomial &p2)
{
     int i; double s[30];
    for(i=0;i<30;i++)
    {
        s[i]=p1.coef[i]*p2.coef[i];
         if(s[i]==0)
		    {continue;}
	     else
        {cout<<s[i]<<"x^"<<i<<"*";}
	}
	cout<<endl;
}
int main()
{
    //Polynomial a,b,c;
    Polynomial p[3];
    double x;
    int z,n = 0;
    char d;
    while(1)
    {
        cout<<"菜单如下："<<endl;
        cout<<"s-设置当前多项式："<<endl;
        cout<<"l-调用assign_coef函数（多项式的某一项）："<<endl;
        cout<<"t-调用add_to_coef函数（将输入的系数累加到多项式的对应的项中）："<<endl;
        cout<<"c-调用clear函数（将当前多项式的各系数清零）："<<endl;
        cout<<"v-显示当前多项式："<<endl;
        cout<<"a-显示所有多项式："<<endl;
        cout<<"d-对当前多项式求导并显示："<<endl;
        cout<<"e-计算当前多项式的值："<<endl;
        cout<<"+-显示A+B的和："<<endl;
        cout<<"--显示A-B的差："<<endl;
        cout<<"*-显示A*B的积："<<endl;
        cout<<"q-退出："<<endl;
        cout<<"请选择"<<endl;
        cin>>d;
        switch(d)
        {
            case 's':cout<<"请输入当前要设置的多项式1(a),2(b),3(c)"; cin>>n;break;
            case 'l':cout<<"请输入系数和指数(用空格隔开)="; cin>>x>>z;p[n].assign_coef(x,z); break;
            case 't':cout<<"请输入需要累加的系数和指数(用空格隔开)="<<endl;cin>>x>>z;p[n].add_to_coef(x,z);break;
            case 'c':p[n].clear();break;
            case 'v':p[n].print();break;
            case 'a':p[0].print();p[1].print();p[2].print();break;
            case 'd':p[n].derivative();break;
            case 'e':p[n].value();break;
            case '+':p[n].sum(p[0],p[1]);break;
            case '-':p[n].differ(p[0],p[1]);break;
            case '*':p[n].multiply(p[0],p[1]);break;
            case 'q':        break;       break;
            default : cout<<"输入错误"<<endl;break;
        }
    }
    return 0;
}
