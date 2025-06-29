#include <stdio.h>
#include<iostream>
using namespace std;
int sum;
void f(int n)
{
 if(n>=3)
  f(n-3);
 if(n>=2)
  f(n-2);
 if(n>=1)
  f(n-1);
 if(n == 0)
  sum++;
}
int main()
{
 int n,num;
 scanf("%d",&n);

 while(n>0)
 {
  sum = 0;
  scanf("%d",&num);
  f(num);
  //printf("%d/n",sum);
  cout<<sum<<endl;
  n--;
 }
return 0;  
}