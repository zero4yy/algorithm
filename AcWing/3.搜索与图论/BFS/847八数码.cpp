#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string start) {
    // 定义目标状态
    string end = "12345678x";
    // 定义队列和dist数组
    queue<string> q;
    unordered_map<string, int> d;
    // 初始状态入队
    q.push(start);
    d[start] = 0;
    // 转移方式
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    
    while(q.size()) {
        string t = q.front();
        q.pop();
        // 记录当前状态距离，如果是终态则返回
        int distance = d[t];
        if(t == end) return distance;
        // 查找x在字符串的下标，然后转换为在矩阵中的坐标
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for(int i = 0; i < 4; i ++) {
            // 求转移后的坐标(a, b)
            int a = x + dx[i], b = y + dy[i];
            // 判断坐标是否越界
            if(a >= 0 && a < 3 && b >= 0 && b < 3) {
                // 得到转移后的状态
                swap(t[k], t[3 * a + b]);
                // 当前状态第一次出现，记录距离，入队
                if(!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                // 还原状态，为下一种转换情况做准备
                swap(t[k], t[3 * a + b]);
            }
        }
    }
    return -1;
}

int main () {
    string start;
    for(int i = 0; i < 9; i ++) {
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start);

    return 0;
}
