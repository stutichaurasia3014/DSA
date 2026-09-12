class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);
        vector<bool> suspicious(n, false);

       
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int ngbr : adj[curr]) {
                if (!suspicious[ngbr]) {
                    suspicious[ngbr] = true;
                    q.push(ngbr);
                }
            }
        }

        
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {
              
                vector<int> ans(n);

                for (int i = 0; i < n; i++) {
                    ans[i] = i;
                }

                return ans;
            }
        }

        
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};