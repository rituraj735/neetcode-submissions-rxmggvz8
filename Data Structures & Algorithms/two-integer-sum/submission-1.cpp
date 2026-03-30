class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; 
        unordered_map<int, int> _mp;
        for(int i =0; i<nums.size(); i++){
            _mp[nums[i]]= i;
        }
        for(int i =0; i<nums.size(); i++){
            if(_mp.find(target-nums[i]) != _mp.end() && _mp[target-nums[i]] != i)
            {
                ans.push_back(i);
                ans.push_back(_mp[target-nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};
