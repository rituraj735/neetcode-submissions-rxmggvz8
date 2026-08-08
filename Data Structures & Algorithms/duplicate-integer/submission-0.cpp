class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int checker = 0;
        for(int i =0; i<nums.size(); i++){
            if(checker == nums[i])
                return true;
            checker = nums[i];
        }
        return false;
    }
};