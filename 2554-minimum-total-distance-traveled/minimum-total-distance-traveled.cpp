
class Solution {
public:
    typedef long long ll;

    ll solve(int ri, int fi, vector<int>& robot,
             vector<int>& positions, vector<vector<ll>>& dp) {

        if (ri >= robot.size()) {
            return 0;
        }

        if (fi >= positions.size()) {
            return LLONG_MAX / 2;
        }

        if (dp[ri][fi] != -1) {
            return dp[ri][fi];
        }

       
        ll take = abs(robot[ri] - positions[fi]) +
                  solve(ri + 1, fi + 1, robot, positions, dp);

       
        ll skip = solve(ri, fi + 1, robot, positions, dp);

        return dp[ri][fi] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int m = robot.size();

        vector<int> positions;

        for (int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos = factory[i][0];

            for (int j = 0; j < limit; j++) {
                positions.push_back(pos);
            }
        }

        int n = positions.size();

        vector<vector<ll>> dp(m + 1,
                               vector<ll>(n + 1, -1));

        return solve(0, 0, robot, positions, dp);
    }
};
