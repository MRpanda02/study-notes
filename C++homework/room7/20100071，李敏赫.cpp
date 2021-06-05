//20100071,李敏赫
#include <iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
class String
{
private:
	char* ptr;
public:
	String()//默认构造函数
	:ptr(NULL)//初始化列表
	{}

	String(char* s)//有参构造，字符串s初始化
	:ptr(s)         //初始化列表
	{}

	String(const String& s) //拷贝构造
	{
	    if(s.ptr)
            {
            ptr=new char[strlen(s.ptr)+1];
            strcpy(ptr,s.ptr);
            }
        else ptr=NULL;

	}
	void operator = (char*s)
	{
	    ptr=s;
	}

	String& operator=(const String&s)//赋值运算符
	{
        if(this==&s)
            return *this;//检测自我赋值
        delete[]ptr;
        ptr=new char[strlen(s.ptr)+1];
        strcpy(ptr,s.ptr);
        return *this;
	}

	void print()const//输出字符串
	{
	    for(int i=0;i<strlen(ptr);i++)
           {
               cout<<ptr[i];
           }
        cout<<endl;

	}

	double length()//返回字符串长度
	{
	    cout<<"The length of string is ";
	    return strlen(ptr);
	}

	String substring(int beGin,int length)//返回当前字符串中下标begin开始，长度为len的子字符串
	{
    String s;
    int i;
        if(beGin>=0&&beGin<strlen(ptr)&&length>0)//合法判断
        {
            s.ptr=new char[length+1];//分配内存
        for(i=0;i<length;i++)
            s.ptr[i]=ptr[beGin++];
        }
        else
            s.ptr=NULL;
    return s;

	}
	void concat(const String& s)//将字符串s接到当前字符串后
	{
	    //表面衔接
	    for(int i=0;i<strlen(ptr);i++)
	    cout<<ptr[i];
	    for(int i=0;i<strlen(s.ptr);i++)
        cout<<s.ptr[i];
        cout<<endl;
	}
	void concat_(const String& s)//合并为一个字符串
	{
        char* ts;//Temporal String 字符数组
        int len=0;
        if(ptr)
        len=strlen(ptr);
        if(s.ptr)
        len=len+strlen(s.ptr);
        if(len!=0)
        {
            ts=new char[len+1];
        }
        else
            ts=NULL;
        if(ts)
        {
            if(ptr)
                strcpy(ts,ptr);
            if(s.ptr)
                strcpy(ts+strlen(ptr),s.ptr);
        }
        cout<<"连接后：";
            ptr=ts;
            for(int i=0;i<strlen(ptr);i++)
           {
               cout<<ptr[i];
           }
            cout<<endl;
	}//contact_函数结束

	~String()//析构
	{
	    if(ptr)
            delete[]ptr;
    }
};

int main()
{

	String s1("hello");

	String s2(s1);

	String s3;

	s1.print();

	s2.print();

	s3.print();

	s1 = "good morning ";

	s2 = "beijing";

	(s3=s2)=s1;

	cout << s1.length() << endl;

	cout << s2.length() << endl;

	cout << s3.length() << endl;

	s1.print();

	s2.print();

	s3.print();

	s1.concat(s2);

	s1.print();

	s2.print();

	String s4;

	s4 = s2.substring(2,3);

	s4.print();

	s4 = s2.substring(2,15);

	s4.print();
	return 0;
}