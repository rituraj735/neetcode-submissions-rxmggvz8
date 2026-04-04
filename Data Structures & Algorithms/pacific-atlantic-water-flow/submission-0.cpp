class Solution {
    int nav_row[4] = {-1,0,1,0};
    int nav_col[4] = {0,1,0,-1};
    void dfs(int r, int c, vector<vector<bool>> &visit, vector<vector<int>> &heights, int rows, int cols){
        visit[r][c] = true;
        for(int i =0; i<4; i++){
            int x = r + nav_row[i];
            int y = c + nav_col[i];
            if(x>=0 && x<rows && y>=0 && y<cols && !visit[x][y] && heights[x][y]>=heights[r][c]){
                dfs(x,y,visit,heights,rows,cols);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int rows = heights.size();
       int cols = heights[0].size();
       vector<vector<bool>> pac(rows,vector<bool>(cols,false));
       vector<vector<bool>> atl(rows,vector<bool>(cols,false));
       //do dfs for top row for pacific and bottom row for atlantic
       //do dfs for left col for pacific and right col for atlantic 
       for(int i=0; i<cols; i++){
            dfs(0,i,pac,heights,rows,cols);
            dfs(rows-1,i,atl,heights,rows,cols);            
       } 
       for(int i=0; i<rows;i++){
            dfs(i,0,pac,heights,rows,cols);
            dfs(i,cols-1,atl,heights,rows,cols);
       }

       vector<vector<int>> res;
       for(int r =0; r<rows; r++){
        for(int c=0; c<cols; c++){
            if(pac[r][c] && atl[r][c]) res.push_back({r,c});
        }
       }
       return res;

    }
};
