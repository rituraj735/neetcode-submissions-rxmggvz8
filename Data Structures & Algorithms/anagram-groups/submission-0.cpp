class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> new_str = strs;
        unordered_map<string,vector<int>> _set;
        for(int i =0; i<new_str.size(); i++){
            
            sort(new_str[i].begin(), new_str[i].end());
            _set[new_str[i]].push_back(i);
            
        }
        vector<vector<string>> ans;
        for(auto x: _set){
            vector<string> _ans;
            for(auto y: x.second){
            _ans.push_back(strs[y]);
            }
            ans.push_back(_ans);
        }
        return ans;
    }
};
