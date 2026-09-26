// class Solution {
// public:
// int dp[2001][2001];
// bool isPalindrome(string &s ,int i,int j){
//     while(i<=j){
//         if(s[i]!=s[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
// int solve(string &s,int i,int j){
//     if(i>=j){
//         return 0;
//     }
 
//  if(dp[i][j] !=-1){
//     return dp[i][j];
//  }

//     if(isPalindrome(s,i,j)){
//         return dp[i][j]= 0;
//     }

//     int cuts=INT_MAX;
//     for(int k=i;k<j;k++){
//         int temp=1+solve(s,i,k) +solve(s,k+1,j);

//         cuts=min(cuts,temp);
//     }
//     return dp[i][j]=cuts;
// }
//     int minCut(string s) {
//         int n =s.length();
//         memset(dp,-1,sizeof(dp));
//         return solve(s,0,n-1);
//     }
// };



class Solution {
public:
    int minCut(string s) {
        int n = s.length();

     
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        
        for (int L = 2; L <= n; L++) {

            for (int i = 0; i < n - L + 1; i++) {

                int j = i + L - 1;

                if (L == 2) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
            }
        }

        
        vector<int> t(n);

        for (int i = 0; i < n; i++) {

            
            if (dp[0][i]) {
                t[i] = 0;
            }
            else {
                t[i] = INT_MAX;

                for (int k = 0; k < i; k++) {

                    
                    if (dp[k + 1][i]) {
                        t[i] = min(t[i], 1 + t[k]);
                    }
                }
            }
        }

        return t[n - 1];
    }
};