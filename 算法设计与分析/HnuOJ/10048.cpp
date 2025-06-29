#include <algorithm>
#include<iostream>
#include <stdio.h>
#include<cstring>
#include <time.h>
 
 
 
using namespace std;
 
 
 
int main()
 
{
 
    //freopen("in.txt","r",stdin);
 
    //freopen("out.txt","w",stdout);
 
    
 
    int i, j, len_a, len_b, ch_num[26] = {0};
 
    char a[1001] = {'/0'}, b[1001] = {'/0'},
 
         ch[27] = "abcdefghijklmnopqrstuvwxyz";
 
    
 
    while(gets(a)!=NULL)
 
    {
 
        gets(b);
 
        len_a = strlen(a);
 
        len_b = strlen(b);
 
        
 
        for(i=0; i<len_a; i++)
 
            for(j=0; j<len_b; j++)
 
            {
 
                if(a[i] == b[j])
 
                {
 
                    b[j] -= b[j]-32;
 
                    ch_num[a[i]-'a']++;
 
                    break;
 
                }
 
            }
 
            
 
        for(i=0; i<26; i++)
 
        {
 
            if(ch_num[i] > 0)
 
            {
 
                for(j=0; j<ch_num[i]; j++)
 
                    printf("%c",ch[i]);
 
            }
 
        }
 
        cout<<endl; 
        
 
        memset(a,'/0',sizeof(a));
 
        memset(b,'/0',sizeof(b));
 
        memset(ch_num,0,sizeof(ch_num));
 
               
 
    }
 
    
 
   // printf("time = %ld ms/n",clock());
 
    
 
    return 0;
 
}