// RECURSION AND MEMEORIZATION

// class Solution {
// public:
// int n;
// unordered_set<string> st;
// int dp[51];
// int solve(int idx,string &s){
//   if(idx>=n){
//     return 0;
//   }
//   if(dp[idx]!=-1){
//     return dp[idx];
//   }
//   string currstring="";
//   int minExtra=n;

//   for(int i=idx;i<n;i++){
//     currstring.push_back(s[i]);
//     int currextra=(st.find(currstring) == st.end()) ? currstring.length() :0;
//     int nextExtra= solve(i+1,s);

//     int totalextra=currextra+nextExtra;

//     minExtra=min(minExtra,totalextra);
//   }
//   return dp[idx]=minExtra;
// }
//     int minExtraChar(string s, vector<string>& dictionary) {
//          n=s.length();

//          for(string &word:dictionary){
//             st.insert(word);
//          }
//          memset(dp,-1,sizeof(dp));

//         return solve(0,s);
//     }
// };



// BOTTOM UP APPROACH


class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();

        unordered_set<string> st;

        for(string &word : dictionary) {
            st.insert(word);
        }

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            dp[i] = 1 + dp[i + 1];

            for(int j = i; j < n; j++) {

                string curr = s.substr(i, j - i + 1);

                if(st.count(curr)) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};
