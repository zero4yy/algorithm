#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = reduce(nums.begin(), nums.end());
        if(s % 2) return false;

        int m = s / 2;
        vector<bool> f(m + 1, false);
        f[0] = true;
        for(int num : nums) {
            for(int j = m; j >= num; j --) {
                
                if(!f[j]) f[j] = f[j - num];
            }
        }
        return f[m];
    }
};

int main() {

    return 0;
}