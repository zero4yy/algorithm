#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int arr[10];
int len, ans;

int solve() {
    int m = len / 2, ans = INF;
    do {
        int first = 0, second = 0;//第一个数和第二个数
        if(arr[0] == 0 || arr[m] == 0)continue;//如果有前导0就跳过本次
        
        for(int i = 0; i < m; i++)    
            first = first * 10 + arr[i];
        for(int i = m; i < len; i++)
            second = second * 10 +arr[i];
//        cout << first << " " << second << endl;
        ans = min(ans, abs(first - second));
    }while(next_permutation(arr, arr + len));//序列排到最后返回false
    if(len == 2)ans = abs(arr[0] - arr[1]);
    return ans;
}
int main() {
    
    int T;
    cin >> T;
    getchar();//清除缓冲区的换行
    while(T--) {
        string str;
        getline(cin, str);//读入一整行字符串
        str.erase(remove(str.begin(),str.end(),' '),str.end());//去除输入中的空格
        len = str.length();
        for(int i = 0; i < len; i++)
            arr[i] = str[i] - '0';
        sort(arr, arr + len);//这一步是必须的，不然遍历时不完全。之前看到一篇题解没有这一步，但是自己试一下会发现有的数据是不对的
        cout << solve() << endl;
    }
    
    return 0;
}