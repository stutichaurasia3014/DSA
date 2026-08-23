class Solution {
public:

bool isCycleDFS(vector<vector<int>>& graph,int u,vector<bool> &visited,vector<bool> &inrecursion){
    visited[u]=true;
    inrecursion[u]=true;

    for(int &v:graph[u]){
        if(visited[v]==false && isCycleDFS(graph,v,visited,inrecursion))
        return true;

        else if(inrecursion[v]==true)
        return true;
    }
    inrecursion[u]=false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();

        vector<bool> visited(v,false);
        vector<bool> inrecursion(v,false);

        for(int i=0;i<v;i++){
            if (!visited[i])
    isCycleDFS(graph, i, visited, inrecursion);
        }

        vector<int> safeNodes;

        for(int i=0;i<v;i++){
           if(inrecursion[i]==false)
           safeNodes.push_back(i);
        }

        return safeNodes;

    }
};