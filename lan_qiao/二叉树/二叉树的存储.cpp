//
// Created by Luzius on 2024/2/9.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 100;
struct Node{
    char v;
    int ls, rs;
}t[N];
void print_tree(int u){  //此处为先序遍历
    if(u){
        cout << t[u].v << ' ';
        print_tree(t[u].ls);
        print_tree(t[u].rs);
    }
}
int main(){
    t[5].v='A'; t[5].ls=7; t[5].rs=3;
    t[7].v='B'; t[7].ls=2; t[7].rs=0;
    t[3].v='C'; t[3].ls=9; t[3].rs=6;
    t[2].v='D';    // t[2].ls=0; t[2].rs=0; 可以不写，因为t[]是全局变量，已初始化为0
    t[9].v='E';    // t[9].ls=0; t[9].rs=0; 可以不写
    t[6].v='F';    // t[6].ls=0; t[6].rs=0; 可以不写
    int root = 5;  //根是tree[5]
    print_tree(5); //输出： A B D C E F
    return 0;
}

//完全二叉树
//#include <bits/stdc++.h>
//using namespace std;
//const int N=100;                   //注意const不能少
//char t[N];                         //简单地用一个数组定义二叉树
//int ls(int p){return p<<1;}        //定位左孩子，也可以写成 p*2
//int rs(int p){return p<<1 | 1;}    //定位右孩子，也可以写成 p*2+1
//int main(){
//    t[1]='A';  t[2]='B';  t[3]='C';
//    t[4]='D';  t[5]='E';  t[6]='F';  t[7]='G';
//    t[8]='H';  t[9]='I';  t[10]='J'; t[11]='K';
//    cout<<t[1]<<":lson="<<t[ls(1)]<<" rson="<<t[rs(1)]; //输出  A:lson=B rson=C
//    cout<<endl;
//    cout<<t[5]<<":lson="<<t[ls(5)]<<" rson="<<t[rs(5)]; //输出  E:lson=J rson=K
//    return 0;
//}
