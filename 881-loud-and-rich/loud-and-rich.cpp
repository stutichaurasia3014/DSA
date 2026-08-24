class Solution {
public:

    int dfs(unordered_map<int, vector<int>> &adj,vector<int>& quiet,vector<int> &ans,int u) {
        if (ans[u] != -1) {
            return ans[u];
        }

        int x = u;

        for (auto &i : adj[u]) {

            int y = dfs(adj, quiet, ans, i);

        
            if (quiet[y] < quiet[x]) {
                x = y;
            }
        }

        return ans[u] = x;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer,
                            vector<int>& quiet) {

        int n = quiet.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < richer.size(); i++) {

            int rich = richer[i][0];
            int poor = richer[i][1];

            adj[poor].push_back(rich);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            if (ans[i] == -1) {
                dfs(adj, quiet, ans, i);
            }
        }

        return ans;
    }
};