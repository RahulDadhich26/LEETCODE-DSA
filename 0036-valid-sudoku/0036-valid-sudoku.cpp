class Solution {
public:
    bool check(vector<vector<char>>& board, int iv, int jv)
    {
        char ch = board[iv][jv];
        for(int c = 0 ; c < 9 ; c++)
        {
            if(board[iv][c]==ch && (c != jv))
                return false;
        }

        for(int r=0 ; r<9 ; r++)
        {
            if(board[r][jv]==ch && (r != iv))
                return false;
        }
        int startRow = floor(iv/3) * 3;
        int startCol = floor(jv/3) * 3;
        for(int r = startRow ; r < startRow+3 ; r++)
        {
            for(int c= startCol ; c<startCol+3 ; c++)
            {
                if(board[r][c]==ch && (r != iv) && (c != jv))
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                if(board[i][j]!='.')
                {
                    bool ans = check(board, i, j);
                    if(!ans)
                        return false;
                }
            }
        }
        return true;
    }
};