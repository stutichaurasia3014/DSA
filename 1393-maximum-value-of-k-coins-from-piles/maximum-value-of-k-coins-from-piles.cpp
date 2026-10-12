// class Solution {
// public:
// int n;
// int dp[1001][2001];
// int solve(int i,vector<vector<int>> &piles,int k){
//     if(i>=n){
//         return 0;
//     }if(dp[i][k] !=-1){
//         return dp[i][k];
//     }
//     int nottaken=solve(i+1,piles,k);
//     int taken=0;
//     int sum=0;

//     for(int j=0;j< min((int)piles[i].size(),k);j++){
//         sum +=piles[i][j];
//         taken=max(taken,sum+solve(i+1,piles,k-(j+1)));
//     }
//     return dp[i][k]=max(taken,nottaken);
// }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//        n=piles.size();

//        memset(dp,-1,sizeof(dp));
//         return solve(0,piles,k);
//     }
// };





class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int coins = 0; coins <= k; coins++) {
                int sum = 0;

                for (int currcoins = 0;
                     currcoins <= min((int)piles[i - 1].size(), coins);
                     currcoins++) {

                    if (currcoins > 0) {
                        sum += piles[i - 1][currcoins - 1];
                    }

                    dp[i][coins] = max(
                        dp[i][coins],
                        sum + dp[i - 1][coins - currcoins]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
