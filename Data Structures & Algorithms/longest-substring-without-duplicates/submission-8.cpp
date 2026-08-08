class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = INT_MIN;
        int l =0;
        if(s.length() == 1) return 1;
        unordered_map<char, int> mp;
        for(int i =0; i<s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                
                res = max(res, i-l);
                l = mp[s[i]]+1; 
                mp[s[i]] = i;
            }
            else {
                mp[s[i]] = i;
                res = max(res, i-l+1);
            }
        }
        
        return res;
    }
};
