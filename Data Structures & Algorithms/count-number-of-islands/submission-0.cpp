class Solution {
public:
    int arr_row[4] = {-1, 1, 0, 0};
    int arr_col[4] = {0, 0, -1, 1};
    void dfs(int row, int col, int ans, vector<vector<int>>&vis, vector<vector<char>>&grid, int n, int m){
        for(int i = 0; i<4; i++){
                if(row+arr_row[i] >=0 && col+arr_col[i] >=0 && row+arr_row[i] <n && col+arr_col[i] <m ){
                    if(grid[row+arr_row[i]][col+arr_col[i]]=='1' && vis[row+arr_row[i]][col+arr_col[i]] == 0){
                        vis[row+arr_row[i]][col+arr_col[i]] = 1;
                        dfs(row+arr_row[i], col+arr_col[i],ans,vis,grid,n,m);
                    }
                        
                }  
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        for(int i =0; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    vis[i][j] = 1;
                    dfs(i,j,ans,vis,grid, rows,cols);
                }
            }
        }
        
        return ans;
    }
};