class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> _ans;
        for(int i =0; i<strs.size(); i++){
            vector<int> char_map(26,0);
            for(int j= 0; j<strs[i].length(); j++){
                char_map[strs[i][j]-'a']++;
            }
            string key = to_string(char_map[0]);
            for(int c: char_map){
                key += "," + to_string(c);
            }
            _ans[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto x: _ans){
            ans.push_back(x.second);
        }
        return ans;
    }
};
