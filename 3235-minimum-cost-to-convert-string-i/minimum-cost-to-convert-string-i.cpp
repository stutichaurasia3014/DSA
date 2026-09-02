class Solution {
public:
void  FloydWarshall(vector<vector<long long >>  &adjmatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
   for(int i=0;i<original.size();i++){
    char s=original[i]-'a';
    char t=changed[i] -'a';

    adjmatrix[s][t]=min(adjmatrix[s][t],(long long)cost[i]);
   }
    
    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                adjmatrix[i][j]=min(adjmatrix[i][j],adjmatrix[i][k]+adjmatrix[k][j]);
            }
        }
    }

}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long >>  adjmatrix(26,vector<long long>(26,INT_MAX));

        FloydWarshall(adjmatrix,original,changed,cost);

        long long ans=0;

        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(adjmatrix[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }
            ans +=adjmatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};