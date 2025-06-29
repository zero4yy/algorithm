#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
struct Node{
	int no, l, r, h;
	bool operator < (const Node &b)const {
		return h == b.h ? no > b.no : h < b.h;
	}
}a[N];
pair<int, int> ans[N];
int main(){
	int n; cin >> n;
	int h, l, r;
	for(int i = 1;i <= n; i++){
		cin >> h >> l >> r;
		a[i] = {i, l, r, h};
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n; i++){
		int x = 0, y = 0;
		for(int j = i - 1;j >= 1;j--){
			if(a[j].l < a[i].l && a[i].l < a[j].r && a[i].h > a[j].h)
			{
				x = a[j].no;
				break;
			}
			
		}
		for(int j = i - 1; j >= 1; j--){
			if(a[j].l < a[i].r && a[i].r < a[j].r && a[i].h > a[j].h)
			{
				y = a[j].no;
				break;
			}
		}
		//cout << x << ' ' << y <<'\n';
		ans[a[i].no] = {x, y};
	}
	for(int i = 1;i <= n;i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}