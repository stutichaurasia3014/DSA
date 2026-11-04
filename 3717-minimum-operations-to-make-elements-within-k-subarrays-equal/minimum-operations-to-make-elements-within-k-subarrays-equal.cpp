class Solution {
public:
    using ll = long long;

    ll minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        ll sumLow = 0, sumHigh = 0;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;

                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;

                low.insert(v);
                sumLow += v;
            }
        };

        auto add = [&](int v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = low.find(v);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= v;
            } else {
                it = high.find(v);
                high.erase(it);
                sumHigh -= v;
            }

            balance();
        };

        vector<ll> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                ll median = *low.rbegin();

                ll operations =
                    median * (ll)low.size() - sumLow +
                    sumHigh - median * (ll)high.size();

                cost.push_back(operations);
            }
        }

       
        const ll INF = LLONG_MAX / 4;

        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                
                dp[i][j] = dp[i - 1][j];

                
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};