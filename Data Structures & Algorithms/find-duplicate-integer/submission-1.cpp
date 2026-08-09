class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //slow 1 3 4 2 2
        // fast 1 4 2 3 2
        // new [2 1 3 4 2] 
        // slow  
        // fast 
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow]; // as the elements range from 1-n
            fast = nums[nums[fast]];
        } while(slow != fast);

        // the fast pointer is already at twice the distance
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};