class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = INT_MIN;
        unordered_map<char, int> mp;
        for(int i =0; i<s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                
                res = max(res, i-mp[s[i]]);
                mp[s[i]] = i;
            }
            else mp[s[i]] = i;
        }
        if(res == INT_MIN) return 0;
        else if(s.length() == 1) return 1;
        else return res;
    }
};
