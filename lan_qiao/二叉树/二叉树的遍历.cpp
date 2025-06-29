//
// Created by Luzius on 2024/2/9.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Node{
    int v;
    int ls, rs;
}t[N];
void preorder(int u){
    if(u){
        cout << t[u].v << ' ';
        preorder(t[u].ls);
        preorder(t[u].rs);
    }
}
void inorder(int u){
    if(u){
        inorder(t[u].ls);
        cout << t[u].v << ' ';
        inorder(t[u].rs);
    }
}
void postorder(int u){
    if(u){
        postorder(t[u].ls);
        postorder(t[u].rs);
        cout << t[u].v << ' ';
    }
}
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        t[i].v = i;
        t[i].ls = a;
        t[i].rs = b;
    }
    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1);
}