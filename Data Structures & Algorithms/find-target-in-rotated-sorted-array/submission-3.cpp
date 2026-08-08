class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1 ;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]<target){
                if(target > nums[l]) l = mid +1;
                else r = mid - 1;
            }
            else if(nums[mid]>target){
                if(target >= nums[l]) r = mid - 1;
                else l = mid+1;
            }
            else return mid;
        }
        return -1;
    }
};
