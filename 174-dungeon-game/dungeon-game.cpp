class Solution {
public:
int m,n;  
int dp[201][201];
int solve(int i,int j,vector<vector<int>> &dungeon){
    if(i>=m ||j>=n){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==m-1 && j==n-1){
        if(dungeon[i][j] >0){
            return 1;
        }
        return abs(dungeon[i][j])+1;
    }
    int right=solve(i,j+1,dungeon);
    int down=solve(i+1,j,dungeon);

    int result=min(right,down)-dungeon[i][j];
    return  dp[i][j]= (result>0) ?result:1;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,dungeon);
    }
};