class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool Row[9][9];
        bool Col[9][9];
        bool Block[9][9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '1'; 
                int boxI = (i/3) * 3 + (j/3);
                // Convert the character digit to an index (0-8) 0 for 9

                if(Row[i][num] || Col[j][num] || Block[boxI][num]) return false;
                
                Row[i][num] = Col[j][num] = Block[boxI][num] = true;
            }
        }
        return true;
    }
};