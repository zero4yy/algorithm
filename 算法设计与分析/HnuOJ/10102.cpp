#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;
int a[MAX][MAX];
int b[MAX];
int N;
int main()
{
    cin >> N;
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            cin >> a[i][j];
    int sum = -1000000, tem = 0;
    for(int i = 0; i < N; i ++)
        for(int j = i; j < N; j ++)
        {
            if(i == j)
            {
                tem = 0;
                for(int k = 0; k < N; k ++)
                {
                    if(tem > 0)
                        tem += a[i][k];
                    else
                        tem = a[i][k];
                    if(tem > sum)
                        sum = tem;
                }
            }
            else
            {
                memset(b, 0, sizeof(b));
                tem = 0;
                for(int k = 0; k < N; k ++)
                    for(int t = i; t <= j; t ++)
                        b[k] += a[t][k];                
                for(int k = 0; k < N; k ++)
                {
                    if(tem > 0)
                        tem += b[k];
                    else
                        tem = b[k];
                    if(tem > sum)
                        sum = tem;
                }
            }
        }
    cout << sum << endl;
    return 0;
}