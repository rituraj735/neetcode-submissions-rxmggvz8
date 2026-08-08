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
                mp[s[i]] = i;
                l = i; 
            }
            else {
                mp[s[i]] = i;
                res = max(res, i-l + 1);
            }
        }
        if(res == INT_MIN) return s.length();
        else return res;
    }
};
