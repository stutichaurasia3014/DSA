// class Solution {
// public:
// int dp[59];
// int solve(int n){
//     if(n==1)
//     return 1;

//     int result=INT_MIN;

//     if(dp[n]!=-1){
//         return dp[n];
//     }

//     for(int i=1;i<=n-1;i++){
//         int prod=i*max(n-i,solve(n-i));

//         result=max(result,prod);
//     }
//     return dp[n]= result;
// }
//     int integerBreak(int n) {
//         memset(dp,-1,sizeof(dp));
//        return solve(n);

//     }
// };




class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);

        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int result = INT_MIN;

            for (int j = 1; j <= i - 1; j++) {
                int prod = j * max(i - j, dp[i - j]);
                result = max(result, prod);
            }

            dp[i] = result;
        }

        return dp[n];
    }
};
