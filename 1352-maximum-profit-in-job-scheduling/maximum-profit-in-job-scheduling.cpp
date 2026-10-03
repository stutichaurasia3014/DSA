class Solution {
public:
    int n;
    int dp[50001];

    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>& array, int i) {
        if (i >= n) {
            return 0;
        }
        if(dp[i] !=-1){
            return dp[i];
        }
        int next = getNextIndex(array, i + 1, array[i][1]);

        int taken = array[i][2] + solve(array, next);

        int nottaken = solve(array, i + 1);

        return dp[i]=max(taken, nottaken);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        n = startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> array(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        auto lambda = [](auto& vec1, auto& vec2) {
            return vec1[0] < vec2[0];
        };

        sort(array.begin(), array.end(), lambda);

        return solve(array, 0);
    }
};