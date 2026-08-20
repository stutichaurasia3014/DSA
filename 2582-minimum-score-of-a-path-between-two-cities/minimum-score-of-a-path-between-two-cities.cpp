
// METHOD 1 USING DFS

// class Solution {
// public:

//     void dfs(unordered_map<int, vector<pair<int, int>>> &adj,
//              int u,
//              vector<bool> &visited,
//              int &result) {

//         visited[u] = true;

//         for (auto &P : adj[u]) {
//             int v = P.first;
//             int d = P.second;

            
//             result = min(result, d);

//             if (!visited[v]) {
//                 dfs(adj, v, visited, result);
//             }
//         }
//     }

//     int minScore(int n, vector<vector<int>>& roads) {

//         unordered_map<int, vector<pair<int, int>>> adj;

    
//         for (vector<int> &vec : roads) {
//             int u = vec[0];
//             int v = vec[1];
//             int d = vec[2];

//             adj[u].push_back({v, d});
//             adj[v].push_back({u, d});
//         }

//         vector<bool> visited(n + 1, false);

//         int result = INT_MAX;

        
//         dfs(adj, 1, visited, result);

//         return result;
//     }
// };



// METHOD 2 USING BFS 

class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<pair<int, int>>> adj;

    
        for (vector<int> &vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> visited(n + 1, false);
        queue<int> que;
        que.push(1);
        visited[1]=true;

        int result = INT_MAX;

        
      while(!que.empty()){
        int u=que.front();
        que.pop();

        for(auto &P:adj[u]){
            int v=P.first;
            int d=P.second;

            result=min(result,d);

            if(!visited[v]){
                visited[v]=true;
                que.push(v);
            }
        }
      }

        return result;
    }
};