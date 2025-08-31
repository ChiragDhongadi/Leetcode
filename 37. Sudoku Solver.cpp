class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char d) {
        for(int i=0; i<9; i++) {
            if(board[row][i] == d) return false;
            if(board[i][col] == d) return false;
        }

        int si = row/3 * 3;
        int sj = col/3 * 3;
        for(int k=0; k<3; k++) {
            for(int l=0; l<3; l++) {
                if(board[si+k][sj+l] == d) return false;
            }
        }
        return true;
    }

    // T.C = O ( 9 ^ 81 )
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.'){

                    for(char d='1'; d<='9'; d++) {
                        if(isValid(board,i,j,d)) {
                            board[i][j] = d;
                            if(solve(board) == true) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};