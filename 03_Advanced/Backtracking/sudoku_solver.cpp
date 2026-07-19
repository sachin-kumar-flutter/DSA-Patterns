class Solution {
public:
    // Entry point: kicks off the backtracking solve on the board
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    // Tries to fill the board using backtracking.
    // Returns true if a complete valid solution is found, false if this path is a dead end.
    bool solve(vector<vector<char>> &board){

        // Scan the board row by row, column by column looking for an empty cell
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                if(board[row][col]!='.') continue; // cell already filled, move to next

                // Try placing each digit 1-9 in this empty cell
                for(int x='1';x<='9';x++){
                    if(isValid(board,row,col,x)){
                        board[row][col]=x;              // choose: place digit

                        if(solve(board)) return true;   // explore: recurse on rest of board
                                                         // if it leads to a full solution, propagate true up

                        board[row][col]='.';            // un-choose: backtrack, this digit didn't work
                    }
                }

                // None of 1-9 worked in this cell -> this branch is invalid.
                // Return false so the previous recursive call undoes its own choice.
                return false;
            }
        }

        // Reached the end of the board with no empty cells left -> fully solved
        return true;
    }

    // Checks if placing digit x at (row, col) violates row, column, or 3x3 box rules
    bool isValid(vector<vector<char>> &board,int row,int col,char x){

        for(int i=0;i<9;i++){
            if(board[row][i]==x) return false;   // x already exists in this row

            if(board[i][col]==x) return false;   // x already exists in this column

            // Map i (0-8) to the correct cell inside the 3x3 box that contains (row, col)
            int boxRow=(row/3) * 3 + i/3;
            int boxCol=(col/3) * 3 + i%3;

            if(board[boxRow][boxCol]==x) return false; // x already exists in this box
        }

        return true; // no conflicts found, x is safe to place
    }
};
