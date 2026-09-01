class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes,
                              int source,
                              int target) {

        if (source == target)
            return 0;

        // stop -> list of bus routes passing through that stop
        unordered_map<int, vector<int>> adj;

        for (int route = 0; route < routes.size(); route++) {
            for (int stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;

        // visited bus routes
        vector<bool> visited(routes.size(), false);

        // Start with all buses available at source
        for (int route : adj[source]) {
            que.push(route);
            visited[route] = true;
        }

        int busCount = 1;

        while (!que.empty()) {

            int size = que.size();

            while (size--) {

                int route = que.front();
                que.pop();

                // Visit every stop of this bus
                for (int stop : routes[route]) {

                    // We reached target
                    if (stop == target)
                        return busCount;

                    // Try all buses available at this stop
                    for (int nextRoute : adj[stop]) {

                        if (!visited[nextRoute]) {

                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }

            busCount++;
        }

        return -1;
    }
};