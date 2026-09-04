class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<int> degree(n, 0);

        for(auto &vec : roads) {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end());

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum += 1LL * degree[i] * (i + 1);
        }

        return sum;
    }
};