class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l =0;
        if(s.length() == 1) return 1;
        unordered_map<char, int> mp;
        for(int i =0; i<s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                
                
                l = max(mp[s[i]]+1,l); 
                
            }
            
                mp[s[i]] = i;
            
            
            res = max(res, i-l+1);
        }
        
        return res;
    }
};
