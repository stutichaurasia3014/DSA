class Solution {
public:
    typedef pair<double, int> P;

    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        unordered_map<int, vector<pair<int, double>>> adj;

        vector<double> result(n, 0.0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<P> pq;

        result[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currProb < result[currNode])
                continue;

            for (auto &temp : adj[currNode]) {
                int adjNode = temp.first;
                double adjProb = temp.second;

                double newProb = currProb * adjProb;

                if (result[adjNode] < newProb) {
                    result[adjNode] = newProb;
                    pq.push({newProb, adjNode});
                }
            }
        }

        return result[end_node];
    }
};