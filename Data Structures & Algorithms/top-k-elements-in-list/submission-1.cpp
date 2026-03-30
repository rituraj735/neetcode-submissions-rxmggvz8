class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }
        vector<vector<int>> frequency_arr(10001);
        for(auto x: mp){
            frequency_arr[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=10000; i>= 0; i--){
            for(auto y: frequency_arr[i]){
                ans.push_back(y);  
                k--;
            }
            if(k==0){
                    break;
                }
                
        }
        return ans;
    }
};
