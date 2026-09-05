// METHOD 1 USING DFS 

// class Solution {
// public:
// void dfs(int u ,vector<int> &visited,unordered_map<int,vector<int>> &adj, stack<int> &st,bool &cycle){
//   visited[u]=1;

//   for(int &v:adj[u]){
//     if(visited[v]==0){
//         dfs(v,visited,adj,st,cycle);
//     }
//     else if(visited[v]==1){
//         cycle=true;
//         return;
//     }
//   }
//   visited[u]=2;
//   st.push(u);
// }
// vector<int> topoSort(vector<vector<int>> &edges ,int &n){
//     unordered_map<int,vector<int>> adj;
//     for(vector<int> &edge:edges){
//         int u=edge[0];
//         int v=edge[1];
//         adj[u].push_back(v);
//     }

//     vector<int> visited(n+1,0);
//     stack<int> st;
//     vector<int>order;
//     bool cycle=false;
//     for(int i=1;i<=n;i++){
//         if(visited[i]==0){
//             dfs(i,visited,adj,st,cycle);
//             if(cycle==true){
//                 return {};
//             }
//         }
//     }

//     while(!st.empty()){
//         order.push_back(st.top());
//         st.pop();
//     }
//     return order;
// }
//     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
//         vector<int> topoRow=topoSort(rowConditions,k);
//          vector<int> topoCol=topoSort(colConditions,k);

//          if(topoRow.empty() || topoCol.empty()){
//             return {};
//          }

//          vector<vector<int>> matrix(k,vector<int>(k,0));

//          for(int i=0;i<k;i++){
//             for(int j=0;j<k;j++){
//                 if(topoRow[i] == topoCol[j]){
//                     matrix[i][j]=topoRow[i];
//                 }
//             }
//          }
//          return matrix;
//     }
// };



// METHOD 2 USING BFS (KAHN'S ALGORITHM)

class Solution {
public:

    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;

       
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topoOrder;

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            topoOrder.push_back(u);

            for (int& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

       
        if (topoOrder.size() != n) {
            return {};
        }

        return topoOrder;
    }

    vector<vector<int>> buildMatrix(
        int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions
    ) {

        vector<int> topoRow = topoSort(rowConditions, k);
        vector<int> topoCol = topoSort(colConditions, k);

        
        if (topoRow.empty() || topoCol.empty()) {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {

                if (topoRow[i] == topoCol[j]) {
                    matrix[i][j] = topoRow[i];
                }
            }
        }

        return matrix;
    }
};