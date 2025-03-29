class Solution {
public:
    vector<vector<string>> result;
    
    void solve(int row, int n, vector<string>& board, vector<int>& columns, 
               vector<int>& diagonal1, vector<int>& diagonal2) {
        if (row == n) { 
            result.push_back(board); // Store solution
            return;
        }

        for (int col = 0; col < n; col++) {
            if (columns[col] || diagonal1[row - col + n - 1] || diagonal2[row + col]) 
                continue; // Skip if under attack

            // Place queen
            board[row][col] = 'Q';
            columns[col] = diagonal1[row - col + n - 1] = diagonal2[row + col] = 1;

            solve(row + 1, n, board, columns, diagonal1, diagonal2); // Recur

            // Backtrack
            board[row][col] = '.';
            columns[col] = diagonal1[row - col + n - 1] = diagonal2[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> columns(n, 0), diagonal1(2 * n - 1, 0), diagonal2(2 * n - 1, 0);
        solve(0, n, board, columns, diagonal1, diagonal2);
        return result;
    }
};