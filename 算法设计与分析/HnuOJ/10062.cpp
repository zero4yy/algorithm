#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int fun(long long n)
{
    long long sum=0;
    int y=1;
    while(n)
    {
        int x = n%10;
        if(x>4)
            x--;
        sum+=x*y;
        y*=9;
        n/=10;
    }
    return sum;
}

int main()
{
    long long x;
    while(cin >> x && x)
    {
        cout << x << ": " << fun(x) << endl;
    }
    return 0;
}