#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int t,b[21],x;
    cin >> t;
    for (int i = 0; i < 21; i++)
    {
        b[i] = 0;
    }
    for (x=0;x<t;x++)
    {
        int n,m=1;
            int a[10001];
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                cin >> a[i];
            }
            while (m <= n)
            {
                if (a[m] != m)
                {
                    swap(a[m], a[a[m]]);
                    b[x]++;
                }
                else
                {
                    m++;
                }
            }
        
    }
    for (x = 0; x < t; x++)
    {
        cout << b[x] << endl;
    }
}