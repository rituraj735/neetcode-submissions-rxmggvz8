class Solution {
public:

    string encode(vector<string>& strs) {
        
        string s="";
        for(int i =0; i<strs.size(); i++){
            s += to_string(strs[i].length()) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int length = 0;
        int i =0;
        while(i<s.length()){
            int j = i;
            while(s[j]!='#' && j<s.length()){
                j++;
            }
            stringstream ss(s.substr(i,j-i));
            int num = 0;
            ss>>num;
            j++;
            ans.push_back(s.substr(j,num));
            i = j+ num;
        }
        return ans;
    }
       
};
