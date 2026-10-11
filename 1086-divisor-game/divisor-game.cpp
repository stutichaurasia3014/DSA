
// class Solution {
// public:
//     int dp[1001];

//     bool solve(int n) {
//         if (n == 1) {
//             return false;
//         }

//         if (dp[n] != -1) {
//             return dp[n];
//         }

//         for (int x = 1; x < n; x++) {
//             if (n % x == 0) {
//                 if (solve(n - x) == false) {
//                     return dp[n] = true;
//                 }
//             }
//         }

//         return dp[n] = false;
//     }

//     bool divisorGame(int n) {
//         memset(dp, -1, sizeof(dp));
//         return solve(n);
//     }
// };





class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);

        dp[1] = false;

        for (int i = 2; i <= n; i++) {
            for (int x = 1; x < i; x++) {
                if (i % x == 0 && dp[i - x] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
