class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() == 0 && t.length()==0)
            return true;
        if(s.length() != t.length())
            return false;
        map<char, int> yoyo;

        for(char c: s){
            yoyo[c]++;
        }
        for(char d: t){
            yoyo[d]--;
        }
        for(auto x: yoyo){
            if(x.second > 0)
                return false;
        }
        return true;
    }
};
