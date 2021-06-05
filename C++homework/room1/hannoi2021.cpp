#include <iostream>
using namespace std;
int hanoi(int n, char src, char medium, char dest);
void move(char src, char dest);
int hanoi(int n, char src,char medium,char dest) 
{
    static int sum=0;
    sum++;
    if (n == 1)
        move(src, dest);
    else
    {
        hanoi(n - 1, src, dest, medium);
        move(src, dest);
        hanoi(n - 1, medium, src, dest);
    }
    return sum;
}
void move(char src, char dest)
{
    cout << "move " << src << " to " << dest << endl;
}
int main()
{
    int n;
    int a;
    cin >> n;
    a = hanoi(n, 'A', 'B', 'C');
    cout << a;
    return 0;
}
