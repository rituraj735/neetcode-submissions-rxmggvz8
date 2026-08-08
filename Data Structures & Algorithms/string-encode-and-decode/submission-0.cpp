class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i=0; i<strs.size(); i++){
            ans += to_string(strs[i].size()) + "#" + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i =0; 
        int length = 1;
        while(s[i]){
            if(s[i+1] == '#' && (s[i] - '0' >=0 && s[i] - '0'<=9)){
                length = s[i]- '0';
                
            }
            int j = i+2; string to_put ="";
            while(j< i+2 + length){
            to_put += s[j];
            j++;
            }
            ans.push_back(to_put);
            i = i+length+2;
        }
        return ans;
    }
};
