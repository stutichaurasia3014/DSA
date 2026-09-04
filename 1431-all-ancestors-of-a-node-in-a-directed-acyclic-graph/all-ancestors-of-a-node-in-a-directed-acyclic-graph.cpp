class Solution {
public:
void dfs(int ancestor,unordered_map<int,vector<int>> &adj,int currnode,vector<vector<int>> &result){
    for(int &neighour:adj[currnode]){
      if(result[neighour].empty() || result[neighour].back() !=ancestor){
        result[neighour].push_back(ancestor);
        dfs(ancestor,adj,neighour,result);
      }
    }
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> adj;

        for(vector<int> &vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<n;i++){
            int ancestor=i;
            dfs(ancestor,adj,i,result);
        }
        return result;
    }
};