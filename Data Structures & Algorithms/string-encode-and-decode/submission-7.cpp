class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string s="";
        for(int i =0; i<strs.size(); i++){
            s += to_string(strs[i].length()) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<string> ans;
        int length = 0;
        int i =0;
        while(s[i]){
            length = 0;
            if(s[i]=='#'){
                if(s[i-1]-'0' >= 0 && s[i-1]-'0' <=9){
                        length = (s[i-1]-'0');
                        ans.push_back(s.substr(i+1, length));
                        i = i + length+1; 
                }
                
            }
            i++;
        }
       
         return ans;
    }
       
};
