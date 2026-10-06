// class Solution {
// public:
// int dp[10001];
// bool solve(vector<int> &nums,int n ,int idx){
//     if(idx==n-1){
//         return true;
//     }
//     if(dp[idx]!=-1){
//         return dp[idx];
//     }
//     for(int i=1;i<=nums[idx];i++){
//         if(solve(nums,n,idx+i)==true){
//             return dp[idx]=true;
//         }
//     }
//     return dp[idx]=false;
// }
//     bool canJump(vector<int>& nums) {
//         int n =nums.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(nums,n,0);
//     }
// };

// BOTTOM UP APPROACH
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        vector<bool> dp(n,false);

        dp[0]=true;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]==true && j+nums[j] >=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};