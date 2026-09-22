// class Solution {
// public:
// int m,n;
// int dp[501][501];
// int solve(string word1, string word2,int i,int j){
//     if(i==m){
//         return n-j;
//     }
//     if(j==n){
//         return m-i;
//     }

//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     if(word1[i]==word2[j]){
//         return dp[i][j]= solve(word1,word2,i+1,j+1);
//     }
//     else{
//         int insertC=1+solve(word1,word2,i,j+1);
//         int deleteC=1+solve(word1,word2,i+1,j);
//         int replaceC=1+solve(word1,word2,i+1,j+1);

//         return dp[i][j]= min({insertC,deleteC,replaceC});
//     }
//     return -1;
// }
//     int minDistance(string word1, string word2) {
//         m=word1.length();
//         n=word2.length();
//        memset(dp,-1,sizeof(dp));
//         return solve(word1,word2,0,0);
//     }
// };



// traverse from right to left 

// class Solution {
// public:
// int m,n;
// int dp[501][501];
// int solve(string word1, string word2,int m,int n){
//     if(m==0 ||n==0){
//         return m+n;
//     }

//     if(dp[m][n]!=-1){
//         return dp[m][n];
//     }

//     if(word1[m-1]==word2[n-1]){
//         return dp[m][n]= solve(word1,word2,m-1,n-1);
//     }
//     else{
//         int insertC=1+solve(word1,word2,m,n-1);
//         int deleteC=1+solve(word1,word2,m-1,n);
//         int replaceC=1+solve(word1,word2,m-1,n-1);

//         return dp[m][n]= min({insertC,deleteC,replaceC});
//     }
//     return -1;
// }
//     int minDistance(string word1, string word2) {
//         m=word1.length();
//         n=word2.length();
//        memset(dp,-1,sizeof(dp));
//         return solve(word1,word2,m,n);
//     }
// };


// BOttom UP APPROACH

class Solution {
public:

    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

      
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],     
                        dp[i - 1][j],    
                        dp[i - 1][j - 1]  
                    });
                }
            }
        }

        return dp[m][n];
    }
};