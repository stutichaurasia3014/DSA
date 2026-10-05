// class Solution {
// public:
// int M=1000000007;
// int dp[1001];
// int solve(int n){
//     if(n==1 ||n==2){
//         return n;
//     }
//     if(n==3)
//     return 5;
//    if(dp[n] !=-1){
//     return dp[n];
//    }
//     return dp[n]=(2*solve(n-1) %M +solve(n-3) %M)%M;
// }
//     int numTilings(int n) {
//         memset(dp,-1,sizeof(dp));
//         return solve(n);
//     }
// };


class Solution {
public:
int M=1000000007;

    int numTilings(int n) {
       if(n==1 || n==2){
        return n;
       }

       vector<int> dp(n+1,0);

       dp[1]=1;
       dp[2]=2;
       dp[3]=5;

       for(int i=4;i<=n;i++){
        dp[i]=(2*dp[i-1] %M + dp[i-3] %M) %M;
       }
       return dp[n];
    }
};