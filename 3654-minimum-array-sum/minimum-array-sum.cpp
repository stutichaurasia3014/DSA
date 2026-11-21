
class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<int>& nums, int k, int op1, int op2, int i) {

        if(i >= n) {
            return 0;
        }

        if(dp[i][op1][op2] != -1) {
            return dp[i][op1][op2];
        }

        int result = INT_MAX;

        result = nums[i] + solve(nums, k, op1, op2, i + 1);

      
        if(op1 > 0) {
            int newVal = (nums[i] + 1) / 2;

            result = min(result,
                newVal + solve(nums, k, op1 - 1, op2, i + 1));
        }

        if(op2 > 0 && nums[i] >= k) {
            int newVal = nums[i] - k;

            result = min(result,
                newVal + solve(nums, k, op1, op2 - 1, i + 1));
        }

        
        if(op1 > 0 && op2 > 0) {
            int newVal = (nums[i] + 1) / 2;

            if(newVal >= k) {
                newVal -= k;

                result = min(result,
                    newVal + solve(nums, k, op1 - 1, op2 - 1, i + 1));
            }
        }

        if(op1 > 0 && op2 > 0 && nums[i] >= k) {
            int newVal = nums[i] - k;
            newVal = (newVal + 1) / 2;

            result = min(result,
                newVal + solve(nums, k, op1 - 1, op2 - 1, i + 1));
        }

        return dp[i][op1][op2] = result;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();

        dp.assign(n, vector<vector<int>>(
            op1 + 1, vector<int>(op2 + 1, -1)));

        return solve(nums, k, op1, op2, 0);
    }
};
