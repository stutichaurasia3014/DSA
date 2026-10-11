
class Solution {
public:
    int dp[1001];

    bool solve(int n) {
        if (n == 1) {
            return false;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        for (int x = 1; x < n; x++) {
            if (n % x == 0) {
                if (solve(n - x) == false) {
                    return dp[n] = true;
                }
            }
        }

        return dp[n] = false;
    }

    bool divisorGame(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
