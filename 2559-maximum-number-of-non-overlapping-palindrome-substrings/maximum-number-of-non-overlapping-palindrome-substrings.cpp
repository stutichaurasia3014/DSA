class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (s[l] == s[r]) {
                    if (len == 2)
                        pal[l][r] = true;
                    else
                        pal[l][r] = pal[l + 1][r - 1];
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
           
            dp[i] = dp[i - 1];

            for (int l = 0; l <= i - k; l++) {
                if (pal[l][i - 1]) {
                    dp[i] = max(dp[i], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};