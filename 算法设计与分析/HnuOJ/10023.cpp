#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct Node{
    double left,right;
}f[2100];//f表示每一个小岛的可放置雷达的范围, 
int cmp(Node a,Node b)
{
    return a.left<b.left;
}//这些范围按左边起点从小到达排序 
int x[2100],y[2100];//为岛的坐标，可以为小数，所以后面要做一下转换处理 
 
int main()
{
    int i,j;
    int n,d;
    int s=0,flag,num;//s为输入的组数,flag用于判断是否存在到不了的小岛
    double k,p;//k表示小岛的横坐标到左右两边的距离 
    while(scanf("%d %d",&n,&d)!=EOF){
        if(n==0&&d==0){
            break;
        }
        s++;
        flag=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&x[i],&y[i]);
            if(y[i]>d){
                flag=-1;
            }
        }
        if(flag==-1){
            printf("Case %d: -1\n",s);
        }
        else{
            for(i=0;i<n;i++){
                k=sqrt(d*d*1.0-y[i]*y[i]*1.0);
                f[i].left=(double)x[i]-k;
                f[i].right=(double)x[i]+k; 
            }
            sort(f,f+n,cmp);
            num=0;
            p=-1e9;
            for(i=0;i<n;i++){//核心:记下当前所以范围中的最小的right,如果下一个范围的left大于这个最小的right,那雷达数加1 
                if(f[i].left>p){
                    num++;
                    p=f[i].right;
                }
                else if(f[i].right<p){
                    p=f[i].right;
                }
            }
            printf("Case %d: %d\n",s,num);
        } 
    }
    return 0;
}