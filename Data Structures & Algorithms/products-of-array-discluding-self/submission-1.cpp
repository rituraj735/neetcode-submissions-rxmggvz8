class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> pfx(n, 1);
        vector<int> sfx(n, 1); 
        for(int i =1; i<nums.size(); i++){
            pfx[i] = pfx[i-1]* nums[i-1];
            sfx[n-1-i] = sfx[n-i]* nums[n-i];
        }
        vector<int> ans(n,1);
        for(int i =0; i<n; i++){
            ans[i] = pfx[i]*sfx[i];
        }
        return ans;
    }
};
