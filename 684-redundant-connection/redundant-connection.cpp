// using dfs

// class Solution {
// public:
// bool dfs(unordered_map<int,vector<int>> &adj,int u,int v, vector<bool> &visited){
//     visited[u]=true;

//     if(u==v){
//         return true;
//     }

//     for(int &neig:adj[u]){
//       if(visited[neig])
//       continue;

//       if(dfs(adj,neig,v,visited)){
//         return true;
//       }
//     }
//     return false;
// }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         unordered_map<int,vector<int>> adj;

//         for(int i=0;i<n;i++){
//             int u=edges[i][0];
//             int v=edges[i][1];
//             vector<bool> visited(n+1,false);
//             if(adj.find(u) !=adj.end() && adj.find(v) !=adj.end() && dfs(adj,u,v,visited)){
//                 return edges[i];
//             }

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         return {};
//     }
// };





// using bfs 

// class Solution {
// public:
// bool bfs(unordered_map<int,vector<int>> &adj,int u,int v, vector<bool> &visited){
//     queue<int> que;
//     visited[u]=true;
//     que.push(u);

//     while(!que.empty()){
//         int curr=que.front();
//         que.pop();
//          if(curr==v){
//         return true;
//          }

//          for(int &neig:adj[curr]){
//       if(visited[neig])
//       continue;
// visited[neig]=true;
//   que.push(neig);
//     }

//     }
    
//     return false;
// }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         unordered_map<int,vector<int>> adj;

//         for(int i=0;i<n;i++){
//             int u=edges[i][0];
//             int v=edges[i][1];
//             vector<bool> visited(n+1,false);
//             if(adj.find(u) !=adj.end() && adj.find(v) !=adj.end() && bfs(adj,u,v,visited)){
//                 return edges[i];
//             }

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         return {};
//     }
// };



// USING DSU

class DSU{
public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;

        }
    }

    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
       int x_parent=find(x);
       int y_parent=find(y);

       if(x_parent == y_parent){
        return;
       }

       if(rank[x_parent]>rank[y_parent]){
         parent[y_parent]=x_parent;
       }
       else if(rank[y_parent]>rank[x_parent]){
        parent[x_parent]=y_parent;
       }
       else {
        parent[x_parent]=y_parent;
        rank[y_parent]++;
       }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(dsu.find(u)==dsu.find(v)){
                return edge;
            }

            dsu.Union(u,v);
        }
         return {}; 
    }
};