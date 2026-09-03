class Solution {
public:
   typedef long long ll;
   typedef pair<ll,ll> P;


 vector<int> dijkstra(unordered_map<int,vector<P>> adj,int src,int n){
  priority_queue<P,vector<P>, greater<P>> pq;

  vector<int> dist(n,INT_MAX);
  dist[src]=0;
  pq.push({0,src});

  while(!pq.empty()){
    ll currwt=pq.top().first;
    ll currNode=pq.top().second;
    pq.pop();

    for(auto adj:adj[currNode]){
        int nextNode=adj.first;
        int nextwt=adj.second;

        if(dist[nextNode]>currwt+nextwt){
            dist[nextNode]=currwt+nextwt;
            pq.push({currwt+nextwt,nextNode});
        }
    }
  }
  return dist;
 }
  
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int E=edges.size();

        unordered_map<int,vector<P>> adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
            vector<int> fromsrc=dijkstra(adj,0,n);
             vector<int> fromdest=dijkstra(adj,n-1,n);

             vector<bool> result(E,false);

             for(int i=0;i<E;i++){
                int u=edges[i][0];
                int v=edges[i][1];
                int w=edges[i][2];

                ll distFromSrc=fromsrc[u];
                ll distFromDest=fromdest[v];

                if(distFromSrc+w+distFromDest == fromsrc[n-1]){
                    result[i]=true;
                }

                 distFromSrc=fromsrc[v];
                 distFromDest=fromdest[u];

                if(distFromSrc+w+distFromDest == fromsrc[n-1]){
                    result[i]=true;
                }
             }

        return result;
    }
};