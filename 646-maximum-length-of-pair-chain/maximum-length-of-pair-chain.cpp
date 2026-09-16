// class Solution {
// public:
// int n;
// vector<vector<int>> dp;
// int solve(vector<vector<int>>& pairs,int i,int prev){
//     if(i>=n){
//       return 0;
//     }
//      if(dp[i][prev+1] !=-1){
//         return dp[i][prev+1];
//      }

//      int take=0;

//      if(prev==-1 || pairs[prev][1] <pairs[i][0]){
//         take =1+solve(pairs,i+1,i);
//      }    

//      int skip=solve(pairs,i+1,prev);

//      return dp[i][prev+1]=max(take,skip);

    
// }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         n=pairs.size();
//         sort(begin(pairs),end(pairs));
//         dp.assign(n,vector<int>(n+1,-1));
//         return solve(pairs,0,-1);
//     }
// };




// TABULATION 

class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
       int n=pairs.size();
        sort(begin(pairs),end(pairs));
       vector<int> dp(n,1);

       int maxLIS=1;

       for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(pairs[j][1] <pairs[i][0]){
                dp[i]=max(dp[i],dp[j]+1);
            maxLIS=max(maxLIS,dp[i]);
            }
            
        }
       }
        return maxLIS;
    }
};