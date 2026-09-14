// class Solution {
// public:
// int solve(vector<int> &nums,int i,int n,vector<int> &dp){
//     if(i>=n){
//         return 0;
//     }
//      if(dp[i]!=-1){
//      return dp[i];
//      }

//     int take=nums[i]+solve(nums,i+2,n,dp);
//     int nottake= solve(nums,i+1,n,dp);

//     return dp[i]=max(take,nottake);
// }
//     int rob(vector<int>& nums) {
//         int n =nums.size();
//         vector<int> dp(n+1,-1);
//         return solve(nums,0,n,dp);
//     }
// };



class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1)
        return nums[0];
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            int taken=nums[i-1]+dp[i-2];
            int nottaken=dp[i-1];

            dp[i]=max(taken,nottaken);
        }
        return dp[n];
    }
};