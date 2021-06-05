/*扩展例题"可变长数组类(CArray)"的功能：
1.为可变长数组类(CArray)添加如下两个成员函数,判断两个CArray类的对象是否相等。只有当两
个数组的长度相等，并且对应的每个数组元素都相等时，两个CArray类的对象才相等。
 bool operator ==(const CArray &);//相等返回true

 bool operator !=(const CArray &);//不相等返回true
2.重载流插入运算符<<，可以直接输出CArray类的对象。(输出每个数组元素)*/
#include<iostream>
#include<cstring>
using namespace std;
class CArray
{
    int size;
    int * ptr;
    public:
    CArray(int s=0);                //有参构造，默认为0
    CArray(CArray & a);             //复制构造
    ~CArray();                      //析构函数
    void push_back(int v);
    CArray & operator = (const CArray & a);
    bool operator ==(const CArray & a);             //判断相等
    bool operator !=(const CArray & a);             //判断不相等
    friend ostream& operator << (ostream &os,CArray & a);                         //输出每个数组元素
    int length() const {return size;}
    int & operator[](int i){
        return ptr[i];
    }
};

// ostream& CArray::operator << (ostream &os,CArray & a)
// {
//     if(!a.length())
//     {
//         for(int i=0;i<a.length();i++)
//             cout << a[i];
//     }
//     else
//         cout << "该可变长数组内没有元素";
//     return os;
// }

ostream & operator << (ostream & os,CArray &a)                  //输出数组内所有元素
{
    if(a.length())
    {
        for(int i=0;i<a.length();i++)
            os << a[i]<< "  ";
    }
    else
        cout << "该可变长数组内没有元素"; 
    return os;
}

CArray::CArray(int s):size(s)
{
    if(s == 0)
        ptr = NULL;
    else
        ptr = new int[s];                   //由参数构造内存
}

CArray::CArray(CArray & a)
{
    if(!a.ptr){                             
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr,a.ptr,sizeof(int)*a.size);       //复制内容
    size = a.size;
}

CArray::~CArray()
{
    if(ptr) delete[]ptr;
}

bool CArray::operator == (const CArray &a)              //判断两个可变长数组内的元素是否相等
{
    if(size == a.size){
        for(int i = 0;i<size;i++){
            if(ptr[i] == a.ptr[i])
                continue;
            break;
        }
        return true;
    }
    else
        return false;
}

bool CArray::operator != (const CArray &a)              //判断两个可变长数组内的元素是否相等,只需在判断等于的重载情况下进行修改即可
{
    if(size == a.size){
        for(int i = 0;i<size;i++){
            if(ptr[i] == a.ptr[i])
                continue;
            break;
        }
        return false;
    }
    else
        return true;
}
CArray& CArray::operator = (const CArray &a)
{
    if(ptr == a.ptr)
        return * this;
    if(a.ptr == NULL){
        if(ptr)
            delete []ptr;
        ptr = NULL;
        size = 0;
        return * this;
    }
    if(size < a.size){
        if(ptr)
            delete []ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr,a.ptr,sizeof(int)*a.size);
    size = a.size;
    return *this;
}

void CArray::push_back(int v)           //在数组尾部添加一个元素
{
    if(ptr){
        int * tmpPtr = new int[size + 1];
        memcpy(tmpPtr,ptr,sizeof(int)*size);
        delete []ptr;
        ptr = tmpPtr;
    }
    else
        ptr = new int[1];
    ptr[size++]=v;
}
int main()
{
    CArray a;
    for(int i=0;i<5;i++)
        a.push_back(i);
    CArray b(a);
    CArray c;
    for(int i=6;i<10;i++)
        c.push_back(i); 
    if(a==b)
        cout<<"相等"<<endl;
    if(a != c)
        cout << "不相等"<<endl;
    cout << a;
}