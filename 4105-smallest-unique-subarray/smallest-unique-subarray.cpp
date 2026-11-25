
class Solution {
public:
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 131;

    bool check(int len, vector<int>& nums) {
        int n = nums.size();

        unordered_map<ll, int> freq;

        ll h1 = 0, h2 = 0;
        ll p1 = 1, p2 = 1;

        for (int i = 0; i < len; i++) {
            h1 = (h1 * BASE + nums[i]) % MOD1;
            h2 = (h2 * BASE + nums[i]) % MOD2;

            if (i < len - 1) {
                p1 = (p1 * BASE) % MOD1;
                p2 = (p2 * BASE) % MOD2;
            }
        }

        auto getKey = [&]() -> ll {
            return h1 * MOD2 + h2;
        };

        freq[getKey()]++;

        for (int i = len; i < n; i++) {
            h1 = (h1 - nums[i - len] * p1 % MOD1 + MOD1) % MOD1;
            h1 = (h1 * BASE + nums[i]) % MOD1;

            h2 = (h2 - nums[i - len] * p2 % MOD2 + MOD2) % MOD2;
            h2 = (h2 * BASE + nums[i]) % MOD2;

            freq[getKey()]++;
        }

        for (auto& it : freq) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
