
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        vector<int> path[26];

        function<void(int, int)> dfs = [&](int node, int par) {

            int ch = s[node] - 'a';

        
            path[ch].push_back(node);

          
            for (int child : adj[node]) {
                dfs(child, node);
            }

            int newParent = par;

            if (path[ch].size() > 1) {
                newParent = path[ch][path[ch].size() - 2];
            }

            if (newParent != -1) {
                ans[newParent] += ans[node];
            }

            path[ch].pop_back();
        };

        dfs(0, -1);

        return ans;
    }
};
