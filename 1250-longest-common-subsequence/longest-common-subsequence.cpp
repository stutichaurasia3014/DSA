class Solution {
public:
int m,n;
vector<vector<int>> dp;
int solve(string &text1,string &text2,int i,int j){
    if(i>=m || j>=n){
        return 0;
    }
     if(dp[i][j] !=-1){
        return dp[i][j];
     }
    if(text1[i]==text2[j]){
       return dp[i][j]=1+solve(text1,text2,i+1,j+1);
    }

    int a=solve(text1,text2,i+1,j);
    int b=solve(text1,text2,i,j+1);

    return dp[i][j]= max(a,b);
}
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.length();
        n=text2.length();
        dp.assign(m,vector<int>(n,-1));
        return solve(text1,text2,0,0);
    }
};