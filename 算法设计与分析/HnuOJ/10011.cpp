#include <iostream>
#include <cstdio>
#include<vector> 
using namespace std;

int main()
{
    int n, m, end = 0;
    while (~scanf("%d%d", &n, &m) && (n + m != -2)) {
        int tot = 0;
        vector<int>v;
        for (int i = n; i >= 1; i--) {
            tot += n - i;
            if (tot >= m) {
                end = i;
                break;
            }
        }

        int k = m + end - (n - end) * (n - end - 1) / 2;
        for (int i = 1; i < end; i++) //printf("%d ", i);
        //printf("%d ", k);
        v.push_back(i);
        v.push_back(k);
        for (int i = n; i >= end; i--)
            if (i != k) //printf("%d ", i);
            v.push_back(i);
        int l=v.size();
        for(int i=0;i<l-1;i++)
            cout<<v[i]<<" ";
            
            cout<<v[l-1];
        printf("\n");
    }

    return 0;
}