
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

 
        vector<vector<int>> cost(n, vector<int>(n, 0));

        vector<vector<int>> factors(n + 1);

        for (int d = 1; d < n; d++) {
            for (int len = 2 * d; len <= n; len += d) {
                factors[len].push_back(d);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int minCost = n;

                for (int d : factors[len]) {
                    int changes = 0;

                    for (int offset = 0; offset < d; offset++) {
                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        while (l < r) {
                            if (s[l] != s[r]) {
                                changes++;
                            }

                            l += d;
                            r -= d;
                        }
                    }

                    minCost = min(minCost, changes);
                }

                cost[i][j] = minCost;
            }
        }

      
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

       

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                for (int p = 0; p <= i - 2; p++) {

                    if (dp[p][j - 1] == INF)
                        continue;

                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
