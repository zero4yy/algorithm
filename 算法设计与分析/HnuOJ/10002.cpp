#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define esp 1e-6
using namespace std;
int n;
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x;y=_y;}
    Point operator - (const Point& b)const{
        return Point(x-b.x,y-b.y);
    }
    double operator * (const Point& b)const{
        return x*b.x+y*b.y;
    }
}p[110];
struct Line{
    Point s,e;
    Line(Point p1,Point p2){
        s=p1,e=p2;
    }
};
double best=1e9;
const Point only(0.5,0.5);
const Point one(sqrt(3.0)/6.0,0.5);
const Point two(1.0-sqrt(3.0)/6.0,0.5);
const Point three(0.5,sqrt(3.0)/6.0);
const Point four(0.5,1.0-sqrt(3.0)/6.0);
const Point lu(0,1),ld(0,0),ru(1,1),rd(1,0);
const Line Line1(one,two),Line2(lu,one),Line3(ru,two),Line4(ld,one),Line5(rd,two);
const Line Line6(three,four),Line7(rd,three),Line8(lu,four),Line9(ld,three),Line10(ru,four);
Line line1[5]={Line1,Line2,Line3,Line4,Line5};
Line line2[5]={Line6,Line7,Line8,Line9,Line10};
double dist(Point n1,Point n2){
    return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}
double Get_nearest_point(Point P,Line L){
    Point result;
    double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    if(t>=0.0&&t<=1.0){
        result.x=L.s.x+(L.e.x-L.s.x)*t;
        result.y=L.s.y+(L.e.y-L.s.y)*t;
    }
    else{
        if(dist(P,L.s)-dist(P,L.e)<esp)result=L.s;
        else result=L.e;
    }
    return dist(result,P);
}
double Get_dist_to_line(int x,Line l[5]){
    double _Min=1e9;
    for(int i=0;i<5;i++)
        _Min=min(_Min,Get_nearest_point(p[x],l[i]));
    return _Min;
}
double solve(Line l[5],Point p1,Point p2){
    int pos1,pos2;
    double ans=0,_Min=1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            double d1=dist(p[i],p1),d2=dist(p[j],p2);
            double d3=Get_dist_to_line(i,l),d4=Get_dist_to_line(j,l);
            if(_Min>d1-d3+d2-d4){_Min=d1-d3+d2-d4;pos1=i;pos2=j;}
        }
    }
    ans=dist(p[pos1],p1)+dist(p[pos2],p2);
    for(int i=0;i<n;i++){
        if(i==pos1||i==pos2)continue;
        ans+=Get_dist_to_line(i,l);
    }
    return ans;
}
int main(){
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n)&&n){best=1e9;
        for(int i=0;i<n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
        if(n==1){printf("%.3lf\n",dist(p[0],only));continue;}
        printf("%.3lf\n",min(solve(line1,one,two),solve(line2,three,four))+esp);
    }
    return 0;
}