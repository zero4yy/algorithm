#include <bits/stdc++.h>

using namespace std;

struct Task {
    int id;
    int pr;
    int time;
};

struct cmpTask {
    bool operator()(const Task &a, const Task &b) {
        return a.pr > b.pr; 
    }
};

string s;
int a, b, c, d;
int ans;
priority_queue<Task, vector<Task>, cmpTask> pq;

int main() {

    int i = 0;
    while(cin >> s) {
        if(s == "add") {
            cin >> a >> b >> c;
            pq.push({a, b, c});
        }
        else if(s == "run"){
            cin >> d;
            while(!pq.empty()) {
                Task t = pq.top();
                pq.pop();
                // cout << t.id << ' ' << t.pr << ' ' << t.time << endl;
                if(d < t.time) {
                    pq.push({t.id, t.pr, t.time - d});
                    break;
                }
                if(d > t.time) {
                    d -= t.time;
                }
            }
        } else {
            break;
        }
        cin.ignore();
    }

    if(pq.empty()) cout << "idle";
    else {
        cout << pq.top().id;
    }
    
    return 0;
}

