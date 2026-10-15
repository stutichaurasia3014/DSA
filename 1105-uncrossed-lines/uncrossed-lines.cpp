// class Solution {
// public:
// int m,n;
// int dp[501][501];
// int solve(int i,int j,vector<int> &nums1,vector<int> &nums2){
// if(i>=m||j>=n){
//     return 0;
// }
// if(dp[i][j] !=-1 ){
//     return dp[i][j];
// }
//  if(nums1[i]==nums2[j]){
//     return 1+solve(i+1,j+1,nums1,nums2);
//  }
//  else{
//   int fix_i=solve(i,j+1,nums1,nums2);
//   int fix_j=solve(i+1,j,nums1,nums2);

//   return dp[i][j]=max(fix_i,fix_j);
//  }
// }
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         m=nums1.size();
//         n=nums2.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(0,0,nums1,nums2);
//     }
// };




class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }
};
