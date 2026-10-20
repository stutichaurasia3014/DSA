class Solution {
public:
int dp[59];
int solve(int n){
    if(n==1)
    return 1;

    int result=INT_MIN;

    if(dp[n]!=-1){
        return dp[n];
    }

    for(int i=1;i<=n-1;i++){
        int prod=i*max(n-i,solve(n-i));

        result=max(result,prod);
    }
    return dp[n]= result;
}
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
       return solve(n);

    }
};