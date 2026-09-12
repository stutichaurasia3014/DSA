class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

  
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

       
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));

       
        vector<vector<vector<int>>> path(
            n + 1,
            vector<vector<int>>(5)
        );

        for (int i = 1; i <= n; i++) {
            long long start = a[i - 1][0];

           
            int low = 0, high = i - 2, prev = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (a[mid][1] < start) {
                    prev = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            for (int k = 1; k <= 4; k++) {
              
                dp[i][k] = dp[i - 1][k];
                path[i][k] = path[i - 1][k];

                
                long long takeWeight = a[i - 1][2];
                vector<int> takePath;

                if (prev != -1) {
                    takeWeight += dp[prev + 1][k - 1];
                    takePath = path[prev + 1][k - 1];
                }

                takePath.push_back(a[i - 1][3]);
                sort(takePath.begin(), takePath.end());

                if (takeWeight > dp[i][k] ||
                    (takeWeight == dp[i][k] &&
                     takePath < path[i][k])) {

                    dp[i][k] = takeWeight;
                    path[i][k] = takePath;
                }
            }
        }

        return path[n][4];
    }
};