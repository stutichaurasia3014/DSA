class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int open) {

       
        if (i >= m || j >= n)
            return false;

      
        if (grid[i][j] == '(')
            open++;
        else
            open--;

        
        if (open < 0)
            return false;

        
        int remaining = (m - 1 - i) + (n - 1 - j);

       
        if (open > remaining)
            return false;

        
        if (dp[i][j][open] != -1)
            return dp[i][j][open];

      
        if (i == m - 1 && j == n - 1) {
            return dp[i][j][open] = (open == 0);
        }

        bool down = solve(grid, i + 1, j, open);
        bool right = solve(grid, i, j + 1, open);

        return dp[i][j][open] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        
        if ((m + n - 1) % 2 != 0)
            return false;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n + 1, -1)
            )
        );

        return solve(grid, 0, 0, 0);
    }
};