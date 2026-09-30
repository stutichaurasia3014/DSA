class Solution {
public:
bool isSubsetSum(vector<int>&nums, int sum){
  int n =nums.size();
       vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
       
       for(int i=0;i<n+1;i++){
           dp[i][0]=true;
       }
       
       for(int i=1;i<n+1;i++){
           for(int j=1;j<sum+1;j++){
               bool skip=dp[i-1][j];
               
               bool take=false;
               
               if(nums[i-1]<=j){
                    take=dp[i-1][j-nums[i-1]];
               }
               dp[i][j]=take||skip;
           }
       }
        return dp[n][sum];
}
    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0){
            return false;
        }

        int s=sum/2;

        return isSubsetSum(nums,s);
    }
};