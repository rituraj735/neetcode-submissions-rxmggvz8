class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int checker = 0;
        map<int, int> _h;
        for(int i =0; i<nums.size(); i++){
            if(_h[nums[i]]==1)
                return true;
            _h[nums[i]]++;
        }
        return false;
    }
};