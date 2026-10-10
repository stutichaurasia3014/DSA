
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        sort(diff.begin(), diff.end(), greater<long long>());

        diff.push_back(0);

        for (int i = 0; i < n; i++) {
            long long gap = diff[i] - diff[i + 1];
            long long cost = gap * (i + 1);

            if (k >= cost) {
                k -= cost;
            } else {
                long long reduction = k / (i + 1);
                long long remainder = k % (i + 1);

                long long level = diff[i] - reduction;
                long long ans = 0;

                for (int j = 0; j <= i; j++) {
                    long long value = level;

                    if (j < remainder) {
                        value--;
                    }

                    ans += value * value;
                }

                for (int j = i + 1; j < n; j++) {
                    ans += diff[j] * diff[j];
                }

                return ans;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};
