class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>> &adj){
        for(auto it: adj[i]){
            if(!vis[it]){
                vis[it] = 1;
                dfs(it,vis,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        int ans = 0;
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                vis[i] = 1;
                dfs(i, vis, adj);
            }
        }
        return ans;
    }
};
