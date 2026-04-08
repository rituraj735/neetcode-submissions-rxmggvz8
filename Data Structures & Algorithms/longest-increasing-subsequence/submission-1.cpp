class Solution {
public:
    int lis(int idx, vector<int> &nums, int prev, vector<vector<int>> &mp){
        if(idx == nums.size()){
            return 0;
        }
        if(mp[idx][prev+1] != -1) return mp[idx][prev+1];
        int len = lis(idx+1, nums, prev, mp);
        if(prev == -1 || nums[idx] > nums[prev]){
            len = max(len, 1+lis(idx+1, nums,idx, mp));
        }
        return mp[idx][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<vector<int>> mp(n,vector<int>(n+1, -1));
       return lis(0,nums,-1, mp); 
    }
};
