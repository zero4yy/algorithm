#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums,int k) {
    	int res=0,count=0;
		for(int l=0,r=0;r<nums.size();r++){
			if(nums[r]==0){
				count++;
				while(count>k){
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
	int n,k; cin>>n;
	vector<int>nums(n,0);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	} 
	cin>>k;
	Solution s;
	cout<<s.findMaxConsecutiveOnes(nums,k);
}
