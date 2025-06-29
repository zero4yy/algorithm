#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct node {
    int x,y,step;
    node () {
        x=y=step=0;
    }
};

int n,m,sx,sy,tx,ty,flag;
int dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={-2,-1,1,2,2,1,-1,-2};

void bfs()
{
    if (abs(sx-tx)/2>m||abs(sy-ty)/2>m)
        return;
    queue<node> q;
    map<pair<int, int>, int> v;
    v.clear();
    pair<int, int> b;
    node cur,nex;
    cur.x=sx;
    cur.y=sy;
    cur.step=0;
   b.first=cur.x;
     b.second=cur.y;
     v[b]=1;
     q.push(cur);
     while (!q.empty()) {
         cur=q.front();
         q.pop();
         if (cur.step>m)
            continue;
     if (cur.x==tx&&cur.y==ty&&cur.step<=m) {
             flag=1;
            return;
       }
        for (int i=0; i<8; i++) {
            nex.x=cur.x+dx[i];
           nex.y=cur.y+dy[i];
            b.first=nex.x;
          b.second=nex.y;
             if (nex.x>=1&&nex.x<=n&&nex.y>=1&&nex.y<=n&&!v[b]) {
                 nex.step=cur.step+1;
                 v[b]=1;
                 q.push(nex);
             }
         }
     }
 }
 
 int main()
 {
     while (~scanf("%d%d",&n,&m)) {
         scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
         flag=0;
        bfs();
         if (flag)
             printf("Knight can reach Queen within %d moves!\n",m);
         else printf("Knight cannot reach Queen within %d moves!\n",m);
     }
     return 0;
 }