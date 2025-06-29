#include <iostream>
#include <vector>
using namespace std;    

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> a;
        for(int i = 1; i <= numRows; i ++) {
            a.push_back(1);
            int len = a.size();
            for(int j = len - 2; j >= 1; j --) {
                a[j] = a[j] + a[j - 1];
            }
            ans.emplace_back(a);
        }
        return ans;
    }
};

int main() {

    return 0;
}