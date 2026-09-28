// class Solution {
// public:
// int dp[201][201];
// int solve(vector<vector<int>>& grid,int i,int j,int m,int n){
//     if(dp[i][j] !=-1){
//         return dp[i][j];
//     }
//     if(i==m-1 &&j==n-1){
//         return dp[i][j]=grid[i][j];
//     }

//     if(i==m-1){
//         return dp[i][j]=grid[i][j] +solve(grid,i,j+1,m,n);
//     }
//     else if(j==n-1){
//         return dp[i][j]=grid[i][j] +solve(grid,i+1,j,m,n);
//     }
//     else{
//         return dp[i][j]= grid[i][j]+min(solve(grid,i,j+1,m,n),solve(grid,i+1,j,m,n));
//     }
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         memset(dp,-1,sizeof(dp));
//         return solve(grid,0,0,m,n);
//     }
// };



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));

        dp[0][0]=grid[0][0];

        for(int row=1;row<m;row++){
          dp[row][0]=grid[row][0] +dp[row-1][0];
        }

        for(int col=1;col<n;col++){
            dp[0][col]=dp[0][col-1]+grid[0][col];
        }


        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j] +min(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};