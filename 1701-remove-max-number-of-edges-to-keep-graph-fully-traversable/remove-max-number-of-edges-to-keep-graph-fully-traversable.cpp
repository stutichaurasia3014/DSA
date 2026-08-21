class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        components = n;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return false;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

        components--;

        return true;
    }

    bool isSingleComponent() {
        return components == 1;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU Alice(n);
        DSU Bob(n);

        
        auto lambda = [](const vector<int>& vec1,
                         const vector<int>& vec2) {
            return vec1[0] > vec2[0];
        };

        sort(begin(edges), end(edges), lambda);

        int usedEdges = 0;

        for (auto &vec : edges) {

            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if (type == 3) {

                bool added = false;

                if (Alice.Union(u, v)) {
                    added = true;
                }

                if (Bob.Union(u, v)) {
                    added = true;
                }

                if (added) {
                    usedEdges++;
                }
            }

            else if (type == 1) {

                if (Alice.Union(u, v)) {
                    usedEdges++;
                }
            }

            else { // type == 2

                if (Bob.Union(u, v)) {
                    usedEdges++;
                }
            }
        }

        if (Alice.isSingleComponent() &&
            Bob.isSingleComponent()) {

            return edges.size() - usedEdges;
        }

        return -1;
    }
};