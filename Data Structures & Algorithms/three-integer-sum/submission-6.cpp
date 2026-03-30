class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            int j = i+1, k = nums.size()-1;
            int target = 0 - (nums[i]);
            while(j<k){
                int sum = nums[j] + nums[k];
                if(sum < target){
                    j++;
                }
                else if(sum > target ){
                    k--;
                }
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    j++; k--;
                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                }
            }
        }
       
        return ans;
    }
};
