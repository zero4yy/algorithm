#include<iostream>
#include<cmath>
struct Point
{
int x,y;
};
int calDis(Point a,Point b)
{
return (a.x-b.x)*(a.x-b.x)
+(a.y-b.y)*(a.y-b.y);
}
int main()
{
Point p[200];
int dis[200][200];
int n,i,j,x,y;
int maxDis,minDis;
bool used[200];
while(scanf("%d",&n)!=EOF)
{
if(n==0) break;
for(i=0;i<n;++i)
{
scanf("%d%d",&(p[i].x),&(p[i].y));
p[i].x--; p[i].y--;
}
for(i=0;i<n;++i)
for(j=i+1;j<n;++j)
dis[j][i]=dis[i][j]=calDis(p[i],p[j]);
std::fill_n(used,n,false);
maxDis=0;
while(true)
{
minDis=60000000;
for(i=0;i<n;++i)
for(j=i+1;j<n;++j)
if(dis[i][j]<minDis)
{
minDis=dis[i][j];
x=i; y=j;
}
if(minDis>maxDis)
maxDis=minDis;
if(used[x]&&used[y])
break;
if(used[x])
{
p[y].y+=2;
used[y]=true;
for(i=0;i<n;++i)
if(i!=y)
dis[y][i]=dis[i][y]=calDis(p[i],p[y]);
}
else if(used[y])
{
p[x].y+=2;
used[x]=true;
for(i=0;i<n;++i)
if(i!=x)
dis[x][i]=dis[i][x]=calDis(p[x],p[i]);
}
else
{
if(p[x].y>p[y].y)
p[x].y+=2;
else
p[y].y+=2;
used[x]=used[y]=true;
for(i=0;i<n;++i)
{
if(i!=y)
dis[y][i]=dis[i][y]=calDis(p[i],p[y]);
if(i!=x)
dis[x][i]=dis[i][x]=calDis(p[i],p[x]);
}
}
}
printf("%.3lf\n",sqrt((double)maxDis));
}
return 0;
}