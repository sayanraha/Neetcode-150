class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    bool find(int i,int j,vector<vector<char>>& board,int idx,string &word)
    {
        if(idx == word.length())
        {
            return true;
        }
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#')
        {
            return false;
        }
        if(board[i][j] != word[idx])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#'; // marked as visited

        for(auto &dir : directions)
        {
            int new_i = i +  dir[0];// direction vector new row index 
            int new_j = j +  dir[1]; // direction vector new col index

            if(find(new_i,new_j,board,idx+1,word)){
                return true;
            }
        }

        board[i][j] = temp;// backtracking step
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();// rows
        n = board[0].size();// cols

        for(int i = 0;i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(board[i][j] == word[0] and find(i,j,board,0,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};