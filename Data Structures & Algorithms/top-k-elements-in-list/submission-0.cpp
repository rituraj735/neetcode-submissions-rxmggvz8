class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }
        map<int,int> reversed;
        for(auto x: mp){
            reversed[x.second] = x.first;
        }
        int y =0;
        vector<int> ans;
        for(auto x: reversed){
            if(y >= mp.size()-k){
                ans.push_back(x.second);
            }
            y++;
        }
        return ans;
    }
};
