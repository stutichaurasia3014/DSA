// class Solution {
// public:
// int dp[1001][1001];
// bool solve(string &s,int i,int j){
//     if(i>=j){
//         return 1;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(s[i]==s[j]){
//         return dp[i][j]=solve(s,i+1,j-1);
//     }
//     return dp[i][j]=0;
// }

//     string longestPalindrome(string s) {
//         int n =s.length();
//         int maxLen=INT_MIN;
//         int sp=0;
//         memset(dp,-1,sizeof(dp));
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(solve(s,i,j)==true){
//                     if(j-i+1 > maxLen){
//                         maxLen=j-i+1;
//                         sp=i;
//                     }
//                 }
//             }
//         }
//         return s.substr(sp,maxLen);
//     }
// };



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int idx = 0;

       
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        
        for (int L = 2; L <= n; L++) {

            for (int i = 0; i <= n - L; i++) {

                int j = i + L - 1;

                if (s[i] == s[j]) {

                    
                    if (L == 2) {
                        dp[i][j] = true;
                    }

                  
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }

                    
                    if (dp[i][j] && L > maxLen) {
                        maxLen = L;
                        idx = i;
                    }
                }
            }
        }

        return s.substr(idx, maxLen);
    }
};