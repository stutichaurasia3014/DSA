class Solution {
public:
int n;
unordered_set<string> st;
int dp[51];
int solve(int idx,string &s){
  if(idx>=n){
    return 0;
  }
  if(dp[idx]!=-1){
    return dp[idx];
  }
  string currstring="";
  int minExtra=n;

  for(int i=idx;i<n;i++){
    currstring.push_back(s[i]);
    int currextra=(st.find(currstring) == st.end()) ? currstring.length() :0;
    int nextExtra= solve(i+1,s);

    int totalextra=currextra+nextExtra;

    minExtra=min(minExtra,totalextra);
  }
  return dp[idx]=minExtra;
}
    int minExtraChar(string s, vector<string>& dictionary) {
         n=s.length();

         for(string &word:dictionary){
            st.insert(word);
         }
         memset(dp,-1,sizeof(dp));

        return solve(0,s);
    }
};