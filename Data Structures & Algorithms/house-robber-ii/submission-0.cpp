class Solution {
private: 
   
    int form_rob(vector<int>&nums, int start, int end){
        int len = end-start+1;
        if(len == 1) return nums[start];
        vector<int> dp(len, -1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for(int i=2; i<len; i++){
            dp[i] = max((nums[start+i]+dp[i-2]), dp[i-1]);
        }
        return dp[len-1];
    }
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if(n == 1) return nums[0];
        return max(form_rob(nums, 0, n-2),form_rob(nums, 1, n-1));
    }
};
