#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int n,max,min,sum;
int num[10][10];//定义一个10x10的矩阵 
 
void move(int m)//第m行右移一次 
{
  int a,i;
  a=num[m][n];
  for(i=n-1;i>=1;i--){
    num[m][i+1]=num[m][i];
  }
  num[m][1]=a;
}
 
void dfs(int k)//k代表着即将要移动的行下标 
{
  int i,j;
  if(k==n+1)  {  //表示关键点处的for循环里面的move已经移动到完了最后一行，求此排列的每列的和，并且暂时得出最小值   
    max=0;
    for(i=1;i<=n;i++){
      sum=0;
      for(j=1;j<=n;j++){
        sum=sum+num[j][i];
      }
      if(sum>max){
        max=sum;
      }
    }
    if(max<min){
      min=max;
    }
    return;
  }
  for(i=1;i<=n;i++){  //关键点 
    move(k);//移动第k行 
    dfs(k+1);//然后以移动第k行为基础，遍历移动后面的行数， 
  }
}
 
int main()
{
  int i,j;
  while((scanf("%d",&n)!=EOF)&&(n!=-1)){
    for(i=1;i<=n;i++) {
      for(j=1;j<=n;j++){
        scanf("%d",&num[i][j]);
      }
    }
max=0;
min=0x7fffffff;// 
    dfs(2);//从第二行开始移动， 
    printf("%d\n",min);
  }
  return 0;
}