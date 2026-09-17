class Solution {
public:
int n;
vector<vector<int>> dp;
 bool isPred(string &prev,string &curr){
    int M=prev.length();
    int N=curr.length();

    if( M>=N || N-M!=1){
        return false;
    }

    int i=0,j=0;

    while(i<M && j<N){
        if(prev[i] == curr[j])
        i++;

        j++;
    }
    return i==M;
 }
 static bool myFunction(string &word1,string &word2){
    return word1.length() <word2.length();
 }

 int lis(vector<string> &words,int prev_idx,int curr_idx){
    if(curr_idx ==n)
    return 0;

    if(dp[curr_idx][prev_idx+1] !=-1)
    return dp[curr_idx][prev_idx+1];

    int taken=0; 
    int not_taken;

    if(prev_idx==-1 || isPred(words[prev_idx],words[curr_idx])){
        taken=1+lis(words,curr_idx,curr_idx+1);
    }
       not_taken=lis(words,prev_idx,curr_idx+1);

       return dp[curr_idx][prev_idx+1]=max(taken,not_taken);
 }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        sort(begin(words),end(words),myFunction);
        dp.assign(n+1,vector<int>(n+1,-1));

        return lis(words,-1,0);
    }
};