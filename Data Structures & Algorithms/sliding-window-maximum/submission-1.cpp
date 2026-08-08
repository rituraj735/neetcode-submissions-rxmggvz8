class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int w_max = INT_MIN; 
        vector<int> res;
        int second_max = INT_MIN, l =0, max_index = -1, second_index = -1;
        int r=0;
        while(r<nums.size()){
            
            while((r-l+1)<=k){
                if(nums[r]>=w_max){
                    
                    second_max = w_max;
                    second_index = max_index;
                    max_index = r;
                    w_max = nums[r];
                }
                r++;
            }
            res.push_back(w_max);
            if(max_index == l){
                w_max = second_max;
                max_index = second_index;
            }
            l++;
        }
        return res;
    }
};
