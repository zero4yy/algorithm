#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

int four[7];//四进制基数
int n,m;//迷宫长宽
int stNum;bool ditu[21][21];//石头数+地图标记
int snakeNum;//蛇的长度
int snakeHeadX,snakeHeadY,snakeBody;//蛇头坐标  + 蛇形状的四进制表示（用四进制记录每一节对于前一节的方向）
bool vis[21][21][1<<14];//蛇头坐标  + 蛇形状的四进制表示 de  三维标记判重函数
int xx[] = {0,1,0,-1};
int yy[] = {1,0,-1,0};

//用于求蛇身每一节对于前一节的方向，0,1,2,3，分别表示右下左上
int check(int a,int b,int c,int d){
    if(c-a==0&&d-b==1) return 0;
    if(c-a==1&&d-b==0) return 1;
    if(c-a==0&&d-b==-1) return 2;
    if(c-a==-1&&d-b==0) return 3;
}

//初始输入+预处理
void init(){
    cin>>snakeHeadX>>snakeHeadY;
    int a=snakeHeadX,b=snakeHeadY,c,d;
    snakeBody=0;
    for(int i=0;i<snakeNum-1;i++){
        cin>>c>>d;
        snakeBody+=four[i]*check(a,b,c,d);
        a=c,b=d;
    }
    cin>>stNum;
    memset(ditu,true,sizeof ditu);
    for(int i=0;i<stNum;i++){
        cin>>a>>b;ditu[a][b]=false;
    }
}

//测试函数 可删除
void show(){
    cout<<n<<" "<<m<<" "<<snakeNum<<endl;
    cout<<snakeHeadX<<" "<<snakeHeadY<<" "<<snakeBody<<endl;
    for(int i=0;i<snakeNum-1;i++){
        int tmp = snakeBody % 4;
        cout<<tmp<<" ";
        snakeBody/=4;
    }cout<<endl;
    cout<<stNum<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<ditu[i][j]<<" ";cout<<endl;
    }
}

//蛇头X,Y坐标 蛇的四进制表示  启发函数数值f（这里是蛇头与洞口（1,1）的曼哈顿距离）
struct node{
    int x,y,snake,step,f;
    node(int xx,int yy,int ssnake,int sstep):x(xx),y(yy),snake(ssnake),step(sstep){
        f=step+abs(x-1)+abs(y-1);
    }
    bool operator < (const node &a) const{
        return f > a.f;
    }
};

//这个函数是通过 蛇头坐标 蛇身四进制 来求 蛇身坐标数组 和 蛇尾对于前一节的方向
void snakeXY(int SX,int SY,int (&snakeX)[8],int (&snakeY)[8],int &c,int d){
    int x = SX,y = SY;
    for(int i=0;i<snakeNum-1;i++){
        int tmp = d % 4; d/=4;
        x+=xx[tmp],y+=yy[tmp];
        snakeX[i] = x ,snakeY[i] = y ;
        if(i==snakeNum-2) c = tmp;
    }
}

//判断蛇头是否能走(x,y)
bool checkN(int x,int y,int a[],int b[]){
    if(x<=0||x>n||y<=0||y>m||ditu[x][y]==false) return false;
    for(int i=0;i<snakeNum-1;i++){
        if(x==a[i]&&y==b[i]) return false;
    }
    return true;
}

//A*算法
int Astar(){
    memset(vis,false,sizeof vis);
    priority_queue<node> q;
    q.push(node(snakeHeadX,snakeHeadY,snakeBody,0));
    vis[snakeHeadX][snakeHeadY][snakeBody] = true;

    while(!q.empty()){
        node p = q.top();q.pop();
        if(p.x==1&&p.y==1) return p.step;

        //这里记录蛇身坐标 和 蛇尾方向
        int snakeX[8],snakeY[8],tail;
        snakeXY(p.x,p.y,snakeX,snakeY,tail,p.snake);

        //右、下、左、上
        for(int i=0;i<4;i++){
            int x = p.x + xx[i],y = p.y + yy[i];
            if(!checkN(x,y,snakeX,snakeY)) continue;
            //这里开始算新的方向四进制  去尾加头
            int body = p.snake - four[snakeNum-2]*tail;
            body*=4;
            if(i==0) body+=2;
            else if(i==1) body+=3;
            else if(i==2) body+=0;
            else body += 1;

            if(vis[x][y][body]) continue;
            vis[x][y][body] = true;
            q.push(node(x,y,body,p.step+1));
        }
    }
    return -1;
}

int main()
{
    four[0]=1;for(int i=1;i<7;i++) four[i] = four[i-1]*4;
    int _=1;
    while(cin>>n>>m>>snakeNum&&n&&m&&snakeNum){
        init();
        cout<<"Case "<<_++<<": ";
        cout<<Astar()<<endl;
    }
    return 0;
}