class Solution {
public:
    int dfs(int i, string& s, unordered_map<int,int> &dp){
        // if(i==s.size()) return 1;
        // if(s[i]=='0') return 0;

        // int res = dfs(i+1, s);
        // if(i< s.size()-1){
        //     if(s[i]== '1' || (s[i]=='2' && s[i+1]<'7')){
        //         res += dfs(i+2,s);
        //     }
        // }
        // return res;
        if(dp[i] && i==s.size()) return dp[s.size()];
        if(s[i]=='0'){
            return 0;
        }
        int res = dfs(i+1, s, dp);
        if(i < s.size()-1){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'7')){
                res += dfs(i+2, s, dp);
            }
        }
        return res;
    }
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(0,s,dp);
    }
};
