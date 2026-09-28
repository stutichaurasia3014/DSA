class Solution {
public:
int dp[201][201];
int solve(vector<vector<int>>& grid,int i,int j,int m,int n){
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    if(i==m-1 &&j==n-1){
        return dp[i][j]=grid[i][j];
    }

    if(i==m-1){
        return dp[i][j]=grid[i][j] +solve(grid,i,j+1,m,n);
    }
    else if(j==n-1){
        return dp[i][j]=grid[i][j] +solve(grid,i+1,j,m,n);
    }
    else{
        return dp[i][j]= grid[i][j]+min(solve(grid,i,j+1,m,n),solve(grid,i+1,j,m,n));
    }
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,m,n);
    }
};