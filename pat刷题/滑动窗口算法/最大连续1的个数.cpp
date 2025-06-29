//»¬¶¯´°¿Ú·¨ 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	int left=0,right=0;
    	int res=0;
    	int len=nums.size();
    	while(right<len){
    		if(nums[right]==1){
    			right++;
			}
			else{
				right++;
				left=right;
			}
			res=max(res,right-left);
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
