class Solution {
public:
    vector<vector<string>> ans;
    bool canPlace(vector<string> &board,int n,int x, int y)
    {
        //Column check
        for(int k = 0;k < x;k++){
            if(board[k][y] == 'Q')
            {
                return false;
            }
        }

        int i,j; // row and col

        i = x-1;
        j = y-1;

        //Left diagonal check

        while(i >= 0 and j >= 0)
        {
            if(board[i][j] == 'Q')
            {
                return false; 
            }
            i--;
            j--;
        }

        i = x-1;
        j = y+1;
        // Right diagonal check

        while(i >= 0 and j < n)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }
    void validNQueen(vector<string> &board,int n,int row){

        //Base case 
        if(row == n)
        {
            ans.push_back(board);
            return;
        }

        for(int col = 0;col < n;col++)
        {
            if(canPlace(board,n,row,col))
            {
                board[row][col] = 'Q';
                validNQueen(board,n,row+1);
                board[row][col] = '.'; //Backtrack step
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        validNQueen(board,n,0);
        return ans;
    }
};