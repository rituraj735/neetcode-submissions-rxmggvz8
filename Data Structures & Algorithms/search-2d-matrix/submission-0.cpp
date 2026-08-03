class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     // first binary search the number of rows - compare the ends of that row to check, which row to move
     int rows = matrix.size();
     int cols = matrix[0].size();
     int l = 0, r = rows-1;
     int row;
     while(l<=r){
        int mid = (l+r)/2;
        if(matrix[mid][0]>target) r = mid-1;
        else if(matrix[mid][cols-1]< target) l = mid+1;
        else{
            row = mid;
            break;
        }
     }
     l = 0, r = cols-1;
     // once fixed, do binary search on the ends.
     while(l<=r){
        int mid = (l+r)/2;
        if(matrix[row][mid]>target) r = mid -1;
        else if(matrix[row][mid]<target) l = mid+1;
        else{
            return true;
        }
     }
     return false;
    }
};
