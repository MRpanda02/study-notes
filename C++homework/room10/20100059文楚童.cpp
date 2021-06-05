/*
在此基础上开发一个小区养狗管理程序。
功能包括：
1.某主人认养一只狗
2.某主人把自己养的狗转让给别的主人
3.能正确显示某主人养了哪些狗，以及某狗的主人是谁

菜单：
a.显示所有的主人(所拥有的狗狗的条数)
b.显示所有的狗狗（暂未收养的狗有标注）
c.显示某主人所拥有的狗狗
d.某主人收养狗
e.某主人转让给另一主人狗
f.显示该小区所有的关系
g.小区新溜进来狗狗
h.小区新入住的居民
i.退出
*/
#include <iostream>
#include <string>
int masternum=0;
int dognum=0;
class CDog;
class CMaster;
CMaster* masterline[20] ={0};
CDog* dogline[30] = {0};
using namespace std;
class CDog{
    private:
    CMaster* pm;
    std::string name;
    public:
    // CDog(){
    // CDog::name = "No name";
    // };
    CDog (std::string DogName = NULL){              //有参构造
    CDog::name = DogName;
    dogline[dognum++] = this;
    pm = NULL;
    };
    void pointer(CMaster* master){
        pm = master;
    }
    string MasterName();                            //主人的名字
    string DogName();                               //自己的名字
    CMaster* DogThink();                            //狗认为的自己的主人   
};

class CMaster{
    
    private:
    CDog *dogs[10];
    int dogNum;
    string Name;

    public:
    CMaster(string MasterName){             //有参构造
    CMaster::Name = MasterName;
    dogNum = 0;
    for(int i=0;i<10;i++)
        dogs[i] = NULL;
    masterline[masternum++] = this;
    };         
    void adoption(CDog*);                    //收养一条狗  
    void print();                           //输出主人收养的狗的信息
    void Transfer(CMaster*,CDog*);                 //转让收养的狗
    string MyName();                        //主人的名字
    int GetDogNum(){return dogNum;}
    CDog* MyDogs(){return *dogs;};
};


CMaster* CDog::DogThink()
{
    return pm;
}
string CDog::DogName()
{
    return CDog::name;
}

string CDog::MasterName()
{
    return pm->MyName();
}

string CMaster::MyName()
{
    return CMaster::Name;
}

void CMaster::print()               //显示用户养的狗的信息（名字和主人的名字）
{
    for(int i=0;i<dogNum;i++){
        //  cout << "Dog "<< i << ":" <<CMaster::dogs[i]->DogName() <<"," <<  " Master : "<< CMaster::dogs[i]->MasterName() << endl;
        //cout << "Dog 1: " <<", Master : "  << endl;
        cout << "Dog "<< i << ":" <<CMaster::dogs[i]->DogName() << endl;
    }
}

void CMaster::Transfer(CMaster* reciever,CDog* animal)
{
    CMaster::dogNum--;
    // reciever->dogs[reciever->dogNum] = CMaster::dogs[CMaster::dogNum];
    reciever->dogs[reciever->dogNum] = animal;
    reciever->dogs[reciever->dogNum]->pointer(reciever);
    for(int a=0;a<CMaster::dogNum;a++){
        if(animal->DogName() == CMaster::dogs[a]->DogName()){
            cout << CMaster::dogs[a]->DogName();
            for(int w=a;w<dogNum;w++)
                CMaster::dogs[w] = CMaster::dogs[w+1];
            break;
        }
    }
    reciever->dogNum++;
}

void CMaster::adoption(CDog* dog){
    dog->pointer(this);
    dogs[dogNum] = dog;
    CMaster::dogNum++;
}


int main()
{
    //创建狗1，2，3
    CDog Dog1("Bessie"),Dog2("Mark"),Dog3("Wolf");
    //主人1
    CMaster Master1("Moon");
    //主人2
    CMaster Master2("Kim");
    //主人1收养狗1，2
    Master1.adoption(&Dog1);
    Master1.adoption(&Dog2);
    //主人1把收养的狗转让给主人2
    // Master1.Transfer(&Master2);
    //主人一收养的情况
    Master1.print();
    Master2.print();
    int i=1,flag=0;
    char dig;
    string name,dogname,RecieveMaster;
    while(i)
    {
        cout << "********************"<<endl;
        cout << "a.显示所有的主人(所拥有的狗狗的条数)" <<endl;
        cout << "b.显示所有的狗狗（暂未收养的狗有标注）"<<endl;
        cout << "c.显示某主人所拥有的狗狗" <<endl;
        cout << "d.某主人收养狗" <<endl;
        cout << "e.某主人转让给另一主人狗" <<endl;
        cout << "f.显示该小区所有的关系" <<endl;
        cout << "g.小区溜进来新的狗狗" <<endl;
        cout << "h.小区入住新的居民" << endl;
        cout << "i.退出" << endl;
        cout << "********************"<<endl;
        cin >> dig;
        switch(dig)
        {
            case 'a':
                for(int j=0;j<masternum;j++){
                    cout << "Master " << j << " : "<<masterline[j]->MyName() << " ( "<<masterline[j]->GetDogNum() <<" ) "<< endl;
                };break;
            case 'b':
                for(int j=0;j<dognum;j++){
                    if(dogline[j]->DogThink())
                        cout << "Dog " << j << " : "<<dogline[j]->DogName() << " ( "<<dogline[j]->DogThink()->MyName() <<" ) "<< endl;
                    else
                        cout << "Dog " << j << " : "<<dogline[j]->DogName() << "(暂未领养）" <<endl;
                };break;
            case 'c':
                flag = 1;
                while(flag){
                    flag = 0;
                    cout << "请输入想要查询的主人的名称：                              按(b)返回菜单" << endl;
                    cin >> name;
                    if(name == "b")
                        break;
                    for(int i=0;i<masternum;i++){
                        if(name == masterline[i]->MyName()){
                            flag = 1;
                        }}
                    if(flag == 0){
                        cout << "该小区中没有拥有该名称的居民！！\n一下是我们小区的所有居民" << endl;
                        for(int j=0;j<masternum;j++)
                            cout << "Master " << j+1 << " : " << masterline[j]->MyName() << endl;
                    }
                    if(flag == 1)
                        break;
                    flag = 1;}
                    if(name == "b")
                        break;
                    cout << "***********" << endl;
                    for(int j=0;j<masternum;j++){
                        if(name == masterline[j]->MyName())
                            masterline[j]->print();
                };cout << "**********" << endl;break;

            case 'd':
                flag = 1;
                while(flag){                        //合法性检测
                flag = 0;
                cout << "请输入想要收养狗的主人的名称：                              按(b)返回菜单" << endl;
                cin >> name;
                if(name == "b")
                    break;
                for(int i=0;i<masternum;i++){
                        if(name == masterline[i]->MyName()){
                            flag = 1;
                        }}
                    if(flag == 0){
                        cout << "该小区中没有拥有该名称的居民！！\n一下是我们小区的所有居民" << endl;
                        for(int j=0;j<masternum;j++)
                            cout << "Master " << j+1 << " : " << masterline[j]->MyName() << endl;
                    }
                    if(flag == 1)
                        break;
                    flag = 1;
                }
                if(name == "b")
                    break;
                flag = 1;
                while(flag){
                    cout << "请输入要被收养的狗的名称：                              按(b)返回菜单" << endl;
                    cin >> dogname;
                    if(dogname == "b")
                        break;
                    flag = 0;
                    for(int i=0;i<dognum;i++){
                        if(dogname == dogline[i]->DogName()){
                            flag = 1;
                        }
                    }
                    for(int i=0;i<masternum;i++){
                        if(name == masterline[i]->MyName()){
                            for(int j=0;j<masterline[i]->GetDogNum();j++){
                                if(dogname == masterline[i]->MyDogs()[j].DogName())
                                    flag += 2;
                            }
                        }
                    }
                    if(flag == 3){
                        cout << "这只狗狗已经是你的了！！" << endl;
                    }
                    if(flag == 0){
                        cout << "该小区里没有这条狗！！ " << endl;
                    }
                    if(flag == 1)
                        break;
                    flag = 1;
                }
                if(dogname == "b")
                    break;
                for(int j=0;j<masternum;j++){
                    if(name == masterline[j]->MyName()){
                        for(int o = 0;o<dognum;o++){
                            if(dogname == dogline[o]->DogName()){
                                masterline[j]->adoption(dogline[o]);
                                cout << "恭喜" <<masterline[j]->MyName() <<"成功领养" << dogline[o]->DogName() << "!!!" <<endl;
                                break;
                            }
                            if(o == dognum){
                                cout << "没有名叫" << dogname << "的狗狗！！" << endl;
                            }
                        }
                        break;
                    }
                };
                break;
                case 'e':                
                flag = 1;
                while(flag){                        //合法性检测
                flag = 0;
                cout << "请输入想要转让狗的主人的名称：                              按(b)返回菜单" << endl;
                cin >> name;
                if(name == "b")
                    break;
                for(int i=0;i<masternum;i++){
                        if(name == masterline[i]->MyName()){
                            flag = 1;
                        }}
                    if(flag == 0){
                        cout << "该小区中没有拥有该名称的居民！！\n一下是我们小区的所有居民" << endl;
                        for(int j=0;j<masternum;j++)
                            cout << "Master " << j+1 << " : " << masterline[j]->MyName() << endl;
                    }
                    if(flag == 1)
                        break;
                    flag = 1;
                }
                if(name == "b")
                    break;
                flag = 1;
                while(flag){                        //合法性检测
                flag = 0;
                cout << "请输入想要接收转让的主人的名称：                              按(b)返回菜单" <<endl;
                cin  >> RecieveMaster;
                if(RecieveMaster == "b")
                    break;
                for(int i=0;i<masternum;i++){
                        if(RecieveMaster == masterline[i]->MyName()){
                            flag = 1;
                        }}
                    if(flag == 0){
                        cout << "该小区中没有拥有该名称的居民！！\n一下是我们小区的所有居民" << endl;
                        for(int j=0;j<masternum;j++)
                            cout << "Master " << j+1 << " : " << masterline[j]->MyName() << endl;
                    }
                    if(name == RecieveMaster){
                        cout << "转让者和受转让者不能为一个人！！" << endl;
                        flag = 0;
                    }
                    if(flag == 1)
                        break;
                    flag = 1;
                }
                if(RecieveMaster == "b")
                    break;
                flag = 1;
                while(flag){
                    cout << "请输入想要转让的" << name << "的狗狗的名字：" << endl;
                    for(int j=0;j<masternum;j++){
                    if(name == masterline[j]->MyName())
                        masterline[j]->print();
                    }
                    cin >> dogname;
                    if(dogname == "b")
                        break;
                    cout << "请输入要转让的的狗的名称：                              按(b)返回菜单" << endl;
                    flag = 0;
                    for(int i=0;i<dognum;i++){
                        if(dogname == dogline[i]->DogName()){
                            flag = 1;
                        }
                    }
                    for(int i=0;i<masternum;i++){
                        if(name == masterline[i]->MyName()){
                            for(int j=0;j<masterline[i]->GetDogNum();j++){
                                if(dogname == masterline[i]->MyDogs()[j].DogName())
                                    flag += 2;
                            }
                        }
                    }
                    if(flag == 1){
                        cout << "这是别人的狗狗！你无权转让！！" << endl;
                    }
                    if(flag == 0){
                        cout << "该小区里没有这条狗！！ " << endl;
                    }
                    if(flag == 3)
                        break;
                    flag = 1;
                }
                if(dogname == "b")
                    break;                
            for(int j=0;j<masternum;j++){
                    if(name == masterline[j]->MyName()){
                        for(int o = 0;o<masternum;o++){
                            if(RecieveMaster == masterline[o]->MyName()){
                                for(int w = 0;w < dognum;w++){
                                    if(dogname == dogline[w]->DogName()){
                                        masterline[j]->Transfer(masterline[o],dogline[w]);
                                        cout << "恭喜" <<masterline[j]->MyName() <<"成功将 "<< dogname <<" 转让给" << masterline[o]->MyName() << "!!!" <<endl;
                                        break;}}}}break;}};break;

            case 'f':
            for(int j=0;j<masternum;j++){
                cout << "*******" << j << "*******" << endl;
                cout << masterline[j]->MyName() << endl;
                masterline[j]->print();
            }break;
            case 'g':
            flag = 1;
            while(flag){
                cout << "请给新溜进来的狗狗起名：                              按(b)返回菜单" << endl;
                flag = 0;
                cin >> dogname;
                if(dogname == "b")
                    break;
                for(int i=0;i<dognum;i++){
                    if(dogname == dogline[i]->DogName()){
                        cout << "拥有这个姓名的狗狗已经存在于该小区中！！" << endl;
                        flag = 1;  
                    }
            }}
            if(dogname == "b")
                break;
            dogline[dognum] = new CDog(dogname);
            cout << "恭喜新狗狗" << dogname << "入住我们小区！！" << endl;
            break;

            case 'h':
            flag = 1;                         //是否有同名的居住者的标志
            while(flag){
            cout << "新入住的居民名字叫：                              按(b)返回菜单" << endl;
            cin >> name;
            if(name == "b")
                break;
            flag = 0;
            for(int i=0;i<masternum;i++){
                if(name == masterline[i]->MyName())
                    cout << "此居民已经存在于该小区中！！" << endl;
                    flag=1;
            }}
            if(name == "b")
                break;
            masterline[masternum] = new CMaster(name);
            cout << "恭喜新居民" << name << "入住我们小区！！" << endl;
            break;
            case 'i': i=0;
        }
    }
    cout <<"退出程序！" <<endl;
    return 0;
}