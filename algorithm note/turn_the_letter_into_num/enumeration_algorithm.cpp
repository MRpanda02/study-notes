#include <iostream>
#include <string>
using namespace std;
const int LETTER_NUM = 5;
int let_val[LETTER_NUM];             //记录"A"~"E"所转换的数字
bool taken[10];                     //记录0～9哪个数字以被替换，被替换为true

int StrtoInt(const string &s)
{
    if(s.length() >1 && let_val[s[0]- 'A'] == 0)
        return -1;
    int intVal = 0;
    for (int i = 0; i < s.length(); i++)
    {
        intVal = 10 * intVal + let_val[s[i] - 'A'];
    }
    return intVal;
}

int main()
{
    freopen("data.txt","r",stdin);
    string s1,s2,s3;
    int num;
    cin >> num;
    while(num--){
        cin >> s1 >> s2 >> s3;
        for(let_val[0] = 0;let_val[0]<=9;let_val[0]++){
            taken[let_val[0]] = true;                   //暂时标记0已被替换，进行尝试，若失败，在跳出循环前将该元素还原为false
            for(let_val[1] = 0;let_val[1]<=9;let_val[1]++){
                if (taken[let_val[1]])
                    continue;
                taken[let_val[1]] = true;
                for(let_val[2] = 0;let_val[2]<=9;let_val[2]++){
                    if (taken[let_val[2]])
                        continue;
                    taken[let_val[2]] = true;
                    for(let_val[3] = 0;let_val[3]<=9;let_val[3]++){
                        if (taken[let_val[3]])
                            continue;
                         taken[let_val[3]] = true;
                        for(let_val[4] = 0;let_val[4]<=9;let_val[4]++){
                            if(taken[let_val[4]])
                                continue;
                            int n1 = StrtoInt(s1);
                            int n2 = StrtoInt(s2);
                            int n3 = StrtoInt(s3);
                            if(n1 >= 0 && n2 >= 0 && n3 >=0 && n1+n2 == n3){
                                cout << n1 <<" + " << n2 <<" = " << n3 << endl;
                                goto found;
                            }
                        }
                        taken[let_val[3]] = false;
                    }
                    taken[let_val[2]] = false;
                }
                taken[let_val[1]] = false;
            }
            taken[let_val[0]] = false;
        }
        cout << "NO RESULT" << endl;
    found: ;
    }
    return 0;
}