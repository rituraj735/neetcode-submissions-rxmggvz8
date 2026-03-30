class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }
        int count=1, previous = INT_MIN;
        int ans = 0;
        for(auto x: mp){
            if(previous == INT_MIN){
                previous = x.first;
            }
            else if(x.first == previous + 1){
                ans = max(++count, ans);
            }
            else {
                count =1;
            }
            previous = x.first;
        }
        return max(ans,count);
    }
};
