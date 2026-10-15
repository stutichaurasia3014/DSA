class Solution {
public:
int m,n;
int dp[501][501];
int solve(int i,int j,vector<int> &nums1,vector<int> &nums2){
if(i>=m||j>=n){
    return 0;
}
if(dp[i][j] !=-1 ){
    return dp[i][j];
}
 if(nums1[i]==nums2[j]){
    return 1+solve(i+1,j+1,nums1,nums2);
 }
 else{
  int fix_i=solve(i,j+1,nums1,nums2);
  int fix_j=solve(i+1,j,nums1,nums2);

  return dp[i][j]=max(fix_i,fix_j);
 }
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};