class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

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
    }

    vector<bool> distanceLimitedPathsExist(
        int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries
    ) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }


        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }

        auto lambda = [](const vector<int>& v1,
                         const vector<int>& v2) {
            return v1[2] < v2[2];
        };

        sort(begin(edgeList), end(edgeList), lambda);

        sort(begin(queries), end(queries), lambda);

        vector<bool> result(queries.size());

        int j = 0;

        for (int i = 0; i < queries.size(); i++) {

            int u = queries[i][0];
            int v = queries[i][1];
            int limit = queries[i][2];
            int idx = queries[i][3];

            
            while (j < edgeList.size() &&
                   edgeList[j][2] < limit) {

                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            result[idx] = (find(u) == find(v));
        }

        return result;
    }
};