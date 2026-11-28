
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;
        int maxFactor = 0;

        for (auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, it[1]);
            maxFactor = max(maxFactor, it[0]);
        }

  
        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= maxFactor; i++) {
            for (int j = i; j <= maxFactor; j += i) {
                cnt[i] += freq[j];
            }
        }

        vector<pair<int, int>> v;

        for (auto &it : items) {
            int factor = it[0];
            int price = it[1];

            int gain = cnt[factor] - 1;

            if (gain > 0 && price <= 2LL * minPrice) {
                v.push_back({price, gain});
            }
        }

        sort(v.begin(), v.end());

        long long ans = budget / minPrice;
        long long remaining = budget;
        long long total = 0;

        for (auto &it : v) {
            long long price = it.first;
            long long gain = it.second;

            long long take = min(gain, remaining / price);

            total += 2LL * take;
            remaining -= take * price;

            ans = max(ans, total + remaining / minPrice);
        }

        return (int)ans;
    }
};
