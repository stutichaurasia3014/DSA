class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        // Case 1: houses 0 to n-2
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i <= n - 2; i++) {
            int take = nums[i] + (i >= 2 ? dp[i - 2] : 0);
            int nottake = dp[i - 1];

            dp[i] = max(take, nottake);
        }

        int result1 = dp[n - 2];

        // Case 2: houses 1 to n-1
        dp.assign(n, 0);

        dp[1] = nums[1];

        for (int i = 2; i <= n - 1; i++) {
            int take = nums[i] + dp[i - 2];
            int nottake = dp[i - 1];

            dp[i] = max(take, nottake);
        }

        int result2 = dp[n - 1];

        return max(result1, result2);
    }
};