// class Solution {
// public:
//     int dp[301][11];
//     int solve(vector<int>& jobDifficulty, int n, int idx, int d) {

//         if (d == 1) {
//             int maxD = 0;

//             for (int i = idx; i < n; i++) {
//                 maxD = max(maxD, jobDifficulty[i]);
//             }

//             return maxD;
//         }

//         if (dp[idx][d] != -1) {
//             return dp[idx][d];
//         }
//         int maxD = 0;
//         int finalResult = INT_MAX;

//         for (int i = idx; i <= n - d; i++) {

//             maxD = max(maxD, jobDifficulty[i]);

//             int result = maxD + solve(jobDifficulty, n, i + 1, d - 1);

//             finalResult = min(finalResult, result);
//         }

//         return dp[idx][d] = finalResult;
//     }

//     int minDifficulty(vector<int>& jobDifficulty, int d) {

//         int n = jobDifficulty.size();
//         memset(dp, -1, sizeof(dp));
//         if (n < d) {
//             return -1;
//         }

//         return solve(jobDifficulty, n, 0, d);
//     }
// };

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();

        if (n < d) {
            return -1;
        }

        vector<vector<int>> dp(n, vector<int>(d + 1, -1));

       
        for (int i = 0; i < n; i++) {
            dp[i][1] = *max_element(
                jobDifficulty.begin() + i,
                jobDifficulty.end()
            );
        }

        for (int days = 2; days <= d; days++) {

            
            for (int i = 0; i <= n - days; i++) {

                int maxD = INT_MIN;
                int result = INT_MAX;

              
                for (int j = i; j <= n - days; j++) {

                    maxD = max(maxD, jobDifficulty[j]);

                    result = min(
                        result,
                        maxD + dp[j + 1][days - 1]
                    );
                }

                dp[i][days] = result;
            }
        }

        return dp[0][d];
    }
};