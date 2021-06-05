/*
某公司有老板Boss、雇员Employee、小时工HourlyWorker和营销人员CommWorker，他们的薪金计算方法如下：
老板实行年薪制，一年15万；雇员按月计酬，方法是基本工资+奖金；小时工按工作时间计算报酬，
方法是工作小时*每小时单价；营销人员按月计酬，方法是基本工资+销售利润*5%。

每类人员都有姓名、职工编号、年龄、性别、工资等数据。
设计计算各类人员报酬的程序，用虚函数getPay()计算各类人员的应得报酬，
用虚函数print()打印输出各位工作人员的基本数据。

提示：将各类人员都共有的属性和行为抽象在类Person中，
包括姓名、职工编号、年龄、性别等，以及函数getPay()和print()。getPay()设计为纯虚函数，
print()设计为一般虚函数，其余类从Person类派生，各类再定义getPay()和print()的实现方法。
此外，每个类需要根据实际情况定义相应的成员函数。
*/
#include <iostream>
using namespace std;

class Person{
    public:
    string Name;
    int Id,Age;
    string Gender;
    double Salary;

    virtual void getPay(int,int) = 0;
    virtual void print(){
        cout << "姓名：" << Name << endl;
        cout << "职工编号：" << Id << endl;
        cout << "年龄：" << Age << endl;
        cout << "性别：" << Gender << endl;
    };
};

class Boss:public Person{
    public:
    Boss(string name,int id,int age,string gender){
        Name = name;
        Id = id;
        Age = age;
        Gender = gender;
        Salary = 0;
    }
    Boss(){Name=" ",Id=0,Age = 0,Gender = " ",Salary = 0;}
    void getPay(int Basicsalary = 0,int Bonus = 0){Salary = 150000;}
    void print(){
        Person::print();
        cout << "Boss一年薪水：" << Boss::Salary << endl;}
};

class Employee:public Person{
    public:
    Employee(string name,int id,int age,string gender){
        Name = name;
        Id = id;
        Age = age;
        Gender = gender;
        Salary = 0;
    }
    Employee(){Name=" ",Id=0,Age = 0,Gender = " ",Salary = 0;}
    void getPay(int Basicsalary,int Bonus){Salary = Basicsalary + Bonus;}
    void print(){
        Person::print();
        cout << "Employee一个月薪水：" << Employee::Salary << endl;}
};

class HourlyWorker:public Person{
    public:
    HourlyWorker(string name,int id,int age,string gender){
        Name = name;
        Id = id;
        Age = age;
        Gender = gender;
        Salary = 0;
    }
    HourlyWorker(){Name=" ",Id=0,Age = 0,Gender = " ",Salary = 0;}
    void getPay(int Worktimes,int PerPay){Salary = Worktimes*PerPay;}
    void print(){
        Person::print();
        cout << "HourlyWorker一天薪水：" << HourlyWorker::Salary << endl;}
};

class Commworker:public Person{
    public:
    Commworker(string name,int id,int age,string gender){
        Name = name;
        Id = id;
        Age = age;
        Gender = gender;
        Salary = 0;
    }
    Commworker(){Name=" ",Id=0,Age = 0,Gender = " ",Salary = 0;}
    void getPay(int BasicSalary,int SalesProfit){Salary = BasicSalary + SalesProfit*0.05;}
    void print(){
        Person::print();
        cout << "CommonWorker一个月薪水：" << Commworker::Salary << endl;}
};

int main()
{
    Boss Boss1("jim",1,30,"Man");
    Boss1.getPay();
    Boss1.print();
    
    Employee Employee1("Bessie",2,25,"Woman");
    Employee1.getPay(3000,500);
    Employee1.print();

    HourlyWorker HourlyWorker1("Mark",3,27,"Man");
    HourlyWorker1.getPay(7,50);
    HourlyWorker1.print();

    Commworker Commworker1("Jessie",4,34,"Woman");
    Commworker1.getPay(3500,20000);
    Commworker1.print();

    return 0;
}