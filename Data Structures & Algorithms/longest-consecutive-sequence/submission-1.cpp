class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }
        int count=1, previous = INT_MIN;
        for(auto x: mp){
            if(previous == INT_MIN){
                previous = x.first;
            }
            if(x.first == previous + 1){
                count++;
            }
            previous = x.first;
        }
        return count;
    }
};
