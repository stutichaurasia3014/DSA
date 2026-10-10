class Solution {
public:
    int m, n;
    int apples[55][55];
    int dp[55][55][11];

    int MOD = 1e9 + 7;

    int solve(int i, int j, int k) {
        if (apples[i][j] < k)
            return 0;

        if (k == 1)
            return apples[i][j] > 0 ? 1 : 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        long long ans = 0;

        // Horizontal cuts
        for (int h = i + 1; h < m; h++) {
            int upper = apples[i][j] - apples[h][j];
            int lower = apples[h][j];

            if (upper > 0 && lower >= k - 1) {
                ans = (ans + solve(h, j, k - 1)) % MOD;
            }
        }

        // Vertical cuts
        for (int v = j + 1; v < n; v++) {
            int left = apples[i][j] - apples[i][v];
            int right = apples[i][v];

            if (left > 0 && right >= k - 1) {
                ans = (ans + solve(i, v, k - 1)) % MOD;
            }
        }

        return dp[i][j][k] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();

        memset(apples, 0, sizeof(apples));
        memset(dp, -1, sizeof(dp));

       
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                apples[i][j] = (pizza[i][j] == 'A')
                               + apples[i + 1][j]
                               + apples[i][j + 1]
                               - apples[i + 1][j + 1];
            }
        }

        return solve(0, 0, k);
    }
};