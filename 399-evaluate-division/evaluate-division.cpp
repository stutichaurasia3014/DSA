class Solution {
public:
    void dfs(
        unordered_map<string, vector<pair<string, double>>> &adj, string src,string dest,unordered_set<string> &visited,double product,double &ans) {
        if (visited.count(src)) {
            return;
        }

        visited.insert(src);

        if (src == dest) {
            ans = product;
            return;
        }

        for (auto &P : adj[src]) {
            string v = P.first;
            double val = P.second;

            if (!visited.count(v) && ans == -1.0) {
                dfs(adj, v, dest, visited, product * val, ans);
            }
        }
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> result;

        for (auto &query : queries) {
            string src = query[0];
            string dest = query[1];

            double ans = -1.0;

            if (adj.find(src) != adj.end() &&
                adj.find(dest) != adj.end()) {

                unordered_set<string> visited;

                dfs(adj, src, dest, visited, 1.0, ans);
            }

            result.push_back(ans);
        }

        return result;
    }
};