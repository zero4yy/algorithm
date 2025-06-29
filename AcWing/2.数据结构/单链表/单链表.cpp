// https://www.acwing.com/problem/content/description/828/
#include <iostream>

using namespace std;

const int N = 100010;

int e[N], ne[N], cnt;
void init() {
    ne[0] = -1; //head 指向-1
    cnt = 1;
}

void add_head(int x) {
    e[cnt] = x;
    ne[cnt] = ne[0];
    ne[0] = cnt;
    cnt++;
}

void add_k(int k, int x) {
    e[cnt] = x;
    ne[cnt] = ne[k];
    ne[k] = cnt;
    cnt ++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m; 
    init();
    cin >> m;
    while(m --) {
        char op;
        cin >> op;
        if(op == 'H') {
            int x;
            cin >> x;
            add_head(x);
        } else if(op == 'D') {
            int k; 
            cin >> k;
            remove(k);
        } else {
            int k, x;
            cin >> k >> x;
            add_k(k, x);
        }
    }

    for(int i = ne[0]; i != -1; i = ne[i]) cout << e[i] << ' ';
}