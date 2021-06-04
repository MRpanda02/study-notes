/*
1、Farmer John's cows are excited to learn that Chinese New Year was recently celebrated, ushering in the year of the Ox, always a bovine favorite.

As we know, the zodiac animals for Chinese calendar years follow a 12-year cycle: Ox, Tiger, Rabbit, Dragon, Snake, Horse, Goat, Monkey, Rooster, Dog, Pig, Rat, and then Ox again.

我们知道，中国的年历遵循12年为周期的12生肖，牛，虎，兔，龙，蛇，马，羊，猴，鸡，狗，猪，鼠，然后又是牛。

Bessie the cow is proud to say she was born in a year of the Ox, many years ago. Her friend Elsie wants to know how many years apart from Bessie she was born, and hopes you can help her deduce this by looking at relationships between the birth years of several cows on the farm.
引诱
Bessie（牛）骄傲的说它出生在很多年前的牛年。他的朋友想要知道Bessie是在多少年前出生的，希望你可以帮助它通过许多头农场里的牛的出生年份的关系。

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains an integer N(1≤N≤100). Each of the next N lines contains an 8-word phrase specifying the relationship between the birth years of two cows. It is of the form "Mildred born in previous Dragon year from Bessie",
Or
输入格式：
第一行输入一个整数（1～100），
每行输入8个字母的单词说明两头牛之间的出生年份的关系
比如：“Mildred出生于Bessie的上一个龙年”

"Mildred born in next Dragon year from Bessie"

“Mildred 出生在Bessie的下一个龙年”
The last word is the name of a cow on the farm, which is either "Bessie" or a cow that has already been mentioned in a previous line of input.

最右一个单词的牛的名字需要是Bessie或是在前面已经被提到的牛的名字

The first word is the name of a cow on the farm who is not "Bessie" and who has not yet been mentioned in the input. All cow names have at most 10 characters that are in the range a..z or A..Z.

第一个单词的牛的名字不可以是Bessie，应该是前面所没提到过的输入，所有牛的名字最长10个英文字母（包括大小写）

The 5th word is one of the 12 zodiac animals above.
第五个单词一定是12生肖的名称之一

The 4th word is either "previous" or "next". For example, if the phrase is "Mildred born in previous Dragon year from Bessie", then Mildred's year of birth was the Dragon year closest to and strictly before (not equal to) Bessie's birth year.
第四个单词要么是“之前”，要么是“之后”。

OUTPUT FORMAT (print output to the terminal / stdout):
Please output the number of years by which Bessie and Elsie's birth years differ. It is guaranteed that this number can be determined by the input given.

输出格式：
请输出Bessie和Elsie的出生年份相差的数字，这保证了这个数字可以由输入所决定
SAMPLE INPUT:

4
Mildred born in previous Dragon year from Bessie
Gretta born in previous Monkey year from Mildred
Elsie born in next Ox year from Gretta
Paulina born in next Dog year from Bessie

SAMPLE OUTPUT:

12

In the input above,

    Elsie was born 12 years before Bessie.
    Mildred was born 9 years before Bessie.
    Gretta was born 17 years before Bessie.
Paulina was born 9 years after Bessie.
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

std::map <std::string,int> animal;
std::map <std::string,int> GapWithBessie;
std::map <std::string,std::string> CowAndZodiac;
int main()
{
    animal["Rat"] = 1;
    animal["Ox"] = 2;
    animal["Tiger"] = 3;     
    animal["Rabbit"] = 4;       
    animal["Dragon"] = 5;
    animal["Snake"] = 6;
    animal["Horse"] = 7;
    animal["Goat"] = 8;
    animal["Monkey"] = 9;
    animal["Rooster"] = 10;
    animal["Dog"] = 11;
    animal["Pig"] = 12;
    string CowName1,temp,Situation,Zodiac,CowName2;
    int Num,gap;
    cin >> Num;
    GapWithBessie["Bessie"] = 0;
    CowAndZodiac["Bessie"] = "Ox";
    for(int i=0;i<Num;i++){
    cin >> CowName1 >> temp >> temp >> Situation >> Zodiac >> temp >> temp >> CowName2;    
        CowAndZodiac[CowName1] = Zodiac;
        if(Situation == "previous"){
            if(animal[CowAndZodiac[CowName2]] != animal[CowAndZodiac[CowName1]])
                gap = (animal[CowAndZodiac[CowName2]] > animal[CowAndZodiac[CowName1]] ? animal[CowAndZodiac[CowName2]] - animal[CowAndZodiac[CowName1]]:12 - animal[CowAndZodiac[CowName1]] + animal[CowAndZodiac[CowName2]]) ;
            else
                gap = 12;
        }
        if(Situation == "next"){
            if(animal[CowAndZodiac[CowName2]] != animal[CowAndZodiac[CowName1]])
                gap = (animal[CowAndZodiac[CowName2]] >= animal[CowAndZodiac[CowName1]] ? animal[CowAndZodiac[CowName1]] + 12 - animal[CowAndZodiac[CowName2]] : animal[CowAndZodiac[CowName1]] - animal[CowAndZodiac[CowName2]]);
            else
                gap = 12;
            gap = -gap;
        }
    GapWithBessie[CowName1] = GapWithBessie[CowName2] + gap;
    if(CowName1 == "Elsie")
        cout<< abs(GapWithBessie["Elsie"])<<endl;
    }
    return 0;
}