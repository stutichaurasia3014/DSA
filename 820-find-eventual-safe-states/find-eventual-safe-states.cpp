// class Solution {
// public:

// bool isCycleDFS(vector<vector<int>>& graph,int u,vector<bool> &visited,vector<bool> &inrecursion){
//     visited[u]=true;
//     inrecursion[u]=true;

//     for(int &v:graph[u]){
//         if(visited[v]==false && isCycleDFS(graph,v,visited,inrecursion))
//         return true;

//         else if(inrecursion[v]==true)
//         return true;
//     }
//     inrecursion[u]=false;
//     return false;
// }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int v=graph.size();

//         vector<bool> visited(v,false);
//         vector<bool> inrecursion(v,false);

//         for(int i=0;i<v;i++){
//             if (!visited[i])
//     isCycleDFS(graph, i, visited, inrecursion);
//         }

//         vector<int> safeNodes;

//         for(int i=0;i<v;i++){
//            if(inrecursion[i]==false)
//            safeNodes.push_back(i);
//         }

//         return safeNodes;

//     }
// };




// Method 2 using bfs (cycle detection - topological method kahn's algorithm )


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        
        vector<vector<int>> adj(n);

        queue<int> que;
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {  
                adj[v].push_back(u);  
                indegree[u]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<bool> isSafe(n, false);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            isSafe[u] = true;

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        vector<int> safeNodes;

        for (int i = 0; i < n; i++) {
            if (isSafe[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};