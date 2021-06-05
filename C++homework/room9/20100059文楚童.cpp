#include <iostream>
#include<string>
using namespace std;


//雇员类employee的声明如下：
class employee{
private:
    string name;
    int id;

public:
    employee(){name = " ",id = 0;};
    void set(string i,int j)
    {
        name = i;
        id = j;
    };   //设置数据成员

    double earnings(){return 0;}
    void print()
    {
        cout << "姓名：" << name << "\n" << "id：" << id << "\n";
    };//输出雇员的姓名和id
};

//类commissionEmployee是指总收入是"销售额*提成比例"的雇员
class commissionEmployee:public employee{
private:
    double grossSales;//销售额
    double commissionRate; //提成比例

public:
        commissionEmployee(){grossSales = 0,commissionRate = 0;};
        void set(string i,int j,double gross,double Rate)
        {
            employee::set(i,j);
            grossSales = gross;
            commissionRate = Rate;
        };   //设置数据成员

        double earnings()
        {
            return grossSales*commissionRate;
        };//返回总收入

        void print()
        {
            employee::print();
            cout << commissionEmployee::earnings() << endl;
        };//输出雇员的姓名,id和总收入

};
//类basePlusCommissionEmployee是指总收入是"基本工资+销售额*提成比例"的雇员
class basePlusCommissionEmployee:public commissionEmployee{
private:
        double baseSalary;  //基本工资
public:
        basePlusCommissionEmployee(){baseSalary = 0;};
        void set(string i,int j,double gross,double Rate,double Salary)
        {
            commissionEmployee::set(i,j,gross,Rate);
            baseSalary = Salary;};   //设置数据成员
        double earnings()
        {
            return baseSalary + commissionEmployee::earnings();
        };//返回总收入

        void print()
        {
            employee::print();
            cout << basePlusCommissionEmployee::earnings() << endl;
        };//输出雇员的姓名,id和总收入
};
//完成以上三个类的定义,编写主函数进行验证。
int main()
{
	basePlusCommissionEmployee  ce;
	ce.set("wang", 123, 30000, 0.2, 500);
	ce.print();
    return 0;
}