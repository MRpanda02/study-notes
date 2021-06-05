#include <iostream>
using namespace std;
class String {

	char* ptr;

public:
	String()//构造函数
	{
		ptr = NULL;
	}

	String(char * s);//构造函数，用字符串s初始化

	String(const String& s);//拷贝构造函数

	void concat(String  &s);//将字符串s连接到当前字符串后

	String substring(int begin, int len);//返回当前字符串中从下标begin开始，长度为len的子字符串	

	String& operator=(String &s);//赋值运算符	
	void operator=(char *s);
	int length()const; //返回字符串长度 

	void print()const; //输出字符串

	~String();//析构函数

};
String String::substring(int begin,int len)
{	
	String s;
	// s = new String;
    int i;
        if(begin>=0&&begin<strlen(ptr)&&len>0)//合法判断
        {
            s.ptr=new char[len+1];//分配内存
        for(i=0;i<len;i++)
            s.ptr[i]=ptr[begin++];
        }
        else
            s.ptr=NULL;
    return s;
}
void String::concat(String &s)
{
	char *ptr_1;
	ptr_1 = new char[strlen(ptr)+strlen(s.ptr)+1];	
	strcpy(ptr_1,ptr);
	strcat(ptr_1,s.ptr);
	ptr = ptr_1;
}

void String::operator=(char *s)
{
	String::ptr = s;
}
int String::length()const
{
	int count=0;
	count = strlen(String::ptr);
	return count;
}
String& String::operator=(String &s)
{
	if(this==&s){
		return *this;
	}
	delete[]ptr;
	ptr=new char[strlen(s.ptr)+1];
	strcpy(ptr,s.ptr);
	return *this;
}
String::String(const String& s)
{
	String::ptr = s.ptr;
}
String::~String()
{
	if(ptr)
		delete ptr;
}
void String::print()const
{
	if(ptr){
	for(int i=0;i<strlen(ptr);i++)
		cout<<ptr[i];
	cout<<endl;
	}
}
String::String(char * s)
{
	String::ptr = s;
}
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