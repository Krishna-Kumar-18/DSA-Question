                                                    // Pure Recursion Solution

    class Solution {
    public:
        bool isSafe(vector<string>&board, int row, int col, int n)
        {
            int row_start = row;
            int col_start = col;

            col--;
            while(col>=0)
            {
                if(board[row][col] == 'Q')
                {
                    return false;
                }
                col--;
            }

            row = row_start;
            col = col_start;
            row--;
            col--;
            while(row>=0 && col>=0)
            {
                if(board[row][col] == 'Q')
                {
                    return false;
                }
                row--;
                col--;
            }

            row = row_start;
            col = col_start;
            row++;
            col--;
            while(row<n && col>=0)
            {
                if(board[row][col] == 'Q')
                {
                    return false;
                }
                row++;
                col--;
            }

            return true;
        }

        void solve(vector<vector<string>>&ans, vector<string>&board, int col, int n)
        {
            if(col == n)
            {
                ans.push_back(board);
                return;
            }

            for(int row=0; row<n; row++)
            {
                if(isSafe(board, row, col, n))
                {
                    board[row][col] = 'Q';
                    solve(ans, board, col+1, n);
                    board[row][col] = '.';
                }
            }
        }

        vector<vector<string>> solveNQueens(int n) 
        {
            vector<vector<string>>ans;
            vector<string>board(n);

            string s(n, '.');

            for(int i=0; i<n; i++)
            {
                board[i] = s;
            }

            solve(ans, board, 0, n);

            return ans;
        }
    };                                            