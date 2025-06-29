//双指针维护一个窗口，最多只有1个0 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	int res=0,count=0;
		for(int l=0,r=0;r<nums.size();r++){
    		if(nums[r]==0){
    			count++;
    			while(count>1){
    				if(nums[l]==0) count--;
    				l++;
				}
			}	
			res=max(res,r-l+1);
		}
		return res;
    }
};
int main(){
	int n; cin>>n;
	vector<int>nums(n,0);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	} 
	Solution s;
	cout<<s.findMaxConsecutiveOnes(nums);
}
