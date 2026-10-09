// class Solution {
// public:
// int n;
// int dp[501][501]; 
// int solve(vector<int>& satisfaction,int i,int time){
//     if(i>=n)
//     return 0;
//     if(dp[i][time] != -1){
//         return dp[i][time];
//     }
//     int include=satisfaction[i]*time+solve(satisfaction,i+1,time+1);

//     int exclude=solve(satisfaction,i+1,time);

//     return dp[i][time]=max(include,exclude);
// }
//     int maxSatisfaction(vector<int>& satisfaction) {
//          n =satisfaction.size();
//          sort(begin(satisfaction),end(satisfaction));
//           memset(dp,-1,sizeof(dp));
//          return solve(satisfaction,0,1);
//     }
// };





class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<long long>> dp(
            n + 1, vector<long long>(n + 1, LLONG_MIN / 2)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= i; t++) {
                long long include =
                    dp[i - 1][t - 1] +
                    1LL * satisfaction[i - 1] * t;

                long long exclude = dp[i - 1][t];

                dp[i][t] = max(include, exclude);
            }
        }

        long long ans = 0;

        for (int t = 1; t <= n; t++) {
            ans = max(ans, dp[n][t]);
        }

        return static_cast<int>(ans);
    }
};