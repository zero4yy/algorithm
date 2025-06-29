// https://www.acwing.com/problem/content/93/
/*
0, 1, 2, 3
0 -> 1 -> 2 -> 3 18
0 -> 2 -> 1 -> 3 20

1. 哪些点被用过(维护一个状态)
2. 目前停在哪个点上

2^20 * 20 = 2 * 10^7

f[state][j] = f[state_k][k] + weight[k][j], state_k = state 除掉 j 之后的集合, state_k要
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1 << 20;

int n;
int f[M][N], weight[N][N];

int main() {
	cin >> n;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			cin >> weight[i][j];

	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;


// 1111...1111 n个1 1 << n - 1
	for(int i = 0; i < 1 << n; i ++) 
		for(int j = 0; j < n; j ++) 
			if(i >> j & 1)
				for(int k = 0; k < n; k ++) 
					if((i - (1 << j)) >> k & 1)
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);

	cout << f[(1 << n) - 1][n - 1] << endl;
	return 0;
}
