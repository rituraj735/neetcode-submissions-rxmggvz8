class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        int resLen = INT_MAX;
        unordered_map<char, int> mp_s, mp_t;
        int l =0;
        for(auto x: t) mp_t[x]++;
        int have =0, need = mp_t.size();
        pair<int, int> res = {-1, -1};
        for(int r=0; r<s.size(); r++){
            char c = s[r];
            mp_s[c]++;
            if(mp_t.count(c) && mp_t[c] == mp_s[c]) have++;
            while(have == need){
                if((r-l+1)< resLen){
                    resLen = r-l+1;
                    res = {l, r};
                }
                mp_s[s[l]]--;
                if(mp_t.count(s[l]) && mp_s[s[l]]< mp_t[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "": s.substr(res.first, resLen);
    }
};
