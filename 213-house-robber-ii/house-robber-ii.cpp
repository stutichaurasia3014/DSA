
// BOTTOM UP APPROACH
// class Solution {
// public:

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1)
//             return nums[0];

//         if (n == 2)
//             return max(nums[0], nums[1]);

//         // Case 1: houses 0 to n-2
//         vector<int> dp(n, 0);

//         dp[0] = nums[0];

//         for (int i = 1; i <= n - 2; i++) {
//             int take = nums[i] + (i >= 2 ? dp[i - 2] : 0);
//             int nottake = dp[i - 1];

//             dp[i] = max(take, nottake);
//         }

//         int result1 = dp[n - 2];

//         // Case 2: houses 1 to n-1
//         dp.assign(n, 0);

//         dp[1] = nums[1];

//         for (int i = 2; i <= n - 1; i++) {
//             int take = nums[i] + dp[i - 2];
//             int nottake = dp[i - 1];

//             dp[i] = max(take, nottake);
//         }

//         int result2 = dp[n - 1];

//         return max(result1, result2);
//     }
// };


// CONSTANT METHOD 


class Solution {
public:
    int solve(vector<int>& nums, int i, int n) {
        
             int prev=0;
       int prevprev=0;
        for(int l=i;l<=n;l++){
   int take = nums[l] + prevprev;
        int nottake = prev;

       int temp = max(take, nottake);

       prevprev=prev;
       prev=temp;
        }
        return prev;
     
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

  

        
        int case1 = solve(nums, 0, n - 2);

       
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};