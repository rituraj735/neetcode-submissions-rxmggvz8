class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;
public:
    bool dfs(int node, int parent){
        
        vis.insert(node);
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(vis.count(it)) return false;
            if(!dfs(it,node)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }
        if(!dfs(0,-1)) return false;
        if(vis.size() != n) return false;
        return true;
    }
};
