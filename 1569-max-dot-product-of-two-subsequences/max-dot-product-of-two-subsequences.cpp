
class Solution {
public:
    int m, n;
    int dp[501][501];

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == m || j == n) {
            return INT_MIN / 2;
        }

        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int product = nums1[i] * nums2[j];

        
        int take = product;

        
        int next = solve(nums1, nums2, i + 1, j + 1);
        if (next > 0) {
            take += next;
        }

        
        int skip_i = solve(nums1, nums2, i + 1, j);
        int skip_j = solve(nums1, nums2, i, j + 1);

        return dp[i][j] = max({take, skip_i, skip_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MIN;
            }
        }

        return solve(nums1, nums2, 0, 0);
    }
};
