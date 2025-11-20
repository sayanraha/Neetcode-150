class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        if(board.size() == 0)return false;

        int n = board.size();
        int row [9][9] = {0};
        int col[9][9] = {0};
        int grid[9][9] = {0};

        for(int i = 0 ;i < n ;i++){
            for(int j = 0; j < board[i].size();j++){
                
                if(board[i][j] != '.'){

                    int d = board[i][j] - '0' - 1, k = i/3 * 3 + j/3;

                    if(row[i][d] || col[j][d] || grid[k][d]) return false;

                    row[i][d] = col[j][d] = grid[k][d] = 1;
                     
                }
            }
        }
        return true;
    }
};