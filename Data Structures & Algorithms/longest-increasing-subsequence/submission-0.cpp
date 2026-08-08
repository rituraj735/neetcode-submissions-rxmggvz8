class Solution {
public:
    int lis(int idx, vector<int> &nums, int prev){
        if(idx == nums.size()){
            return 0;
        }
        int len = lis(idx+1, nums, prev);
        if(nums[idx] > prev){
            len = max(len, 1+lis(idx+1, nums,nums[idx]));
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
       return lis(0,nums,-1); 
    }
};
