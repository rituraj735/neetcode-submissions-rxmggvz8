class Solution {
public:
    bool check_rows(int r, int c, vector<vector<char>> board){
        for(int i =0; i<9; i++){
            if (i!= c && board[r][i] != '.' && board[r][c] != '.' && board[r][i] == board[r][c])
                return false;
        }
        return true;
    }
    bool check_cols(int r, int c, vector<vector<char>> board){
        for(int i =0; i<9; i++){
            if (i!= r && board[i][c] != '.' && board[r][c] != '.' && board[i][c] == board[r][c])
                return false;
        }
        return true;
    }
    bool check_cube(int r, int c, vector<vector<char>> board){
        int r_begin = 0, r_end =0, c_begin = 0, c_end =0;
        if( r >= 0 && r<= 2 ){
            r_begin = 0;
            r_end = 2; 
            if( c>=0 && c<=2){
            c_begin = 0; 
            c_end = 2;
            }
            else if(c>=3 && c<=5){
            c_begin = 3; 
            c_end = 5;
            }
            else if(c>=6 && c<=8){
            c_begin = 6; 
            c_end = 8;
            }
        }
        if( r >= 3 && r<= 5 ){
            r_begin = 3;
            r_end = 5; 
            if( c>=0 && c<=2){
            c_begin = 0; 
            c_end = 2;
            }
            else if(c>=3 && c<=5){
            c_begin = 3; 
            c_end = 5;
            }
            else if(c>=6 && c<=8){
            c_begin = 6; 
            c_end = 8;
            }
        }
        if( r >= 6 && r<= 8 ){
            r_begin = 6;
            r_end = 8; 
            if( c>=0 && c<=2){
            c_begin = 0; 
            c_end = 2;
            }
            else if(c>=3 && c<=5){
            c_begin = 3; 
            c_end = 5;
            }
            else if(c>=6 && c<=8){
            c_begin = 6; 
            c_end = 8;
            }
        }
        
        for(int i =r_begin; i<=r_end; i++){
        for(int j =c_begin; j<=c_end; j++){
            if (i!= r && j != c && board[i][j] != '.' && board[r][c] != '.' && board[i][j] == board[r][c])
            return false;
        }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r =0; r<10; r++){
            for(int c=0; c<10; c++){
                return check_rows(r,c, board) && 
                check_cols(r,c, board) && 
                check_cube(r,c, board);
            }
        }
        return false;
    }
};
