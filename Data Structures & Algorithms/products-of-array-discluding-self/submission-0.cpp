class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        bool is_zero = false;
        for(int i: nums){
            if(i !=0)
                product *= i;
            else 
                is_zero = true;
            
        }
        vector<int> output;
        for(int i =0; i<nums.size(); i++){
            if(is_zero==true && nums[i]!=0 )
                output.push_back(0);
            else if(is_zero ==true && nums[i]==0)
                output.push_back(product);
            else
                output.push_back(product/nums[i]);

        }
        return output;
    }
};
