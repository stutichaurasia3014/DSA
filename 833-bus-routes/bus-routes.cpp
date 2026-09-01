class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes,
                              int source,
                              int target) {

        if (source == target)
            return 0;

       
        unordered_map<int, vector<int>> adj;

        for (int route = 0; route < routes.size(); route++) {
            for (int stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;

        vector<bool> visited(routes.size(), false);

      
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

                for (int stop : routes[route]) {

                    if (stop == target)
                        return busCount;

                  
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