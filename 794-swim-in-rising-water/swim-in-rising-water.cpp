class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool possibleToReach(vector<vector<int>>& grid, int i, int j, int t,
                         vector<vector<bool>>& visited) {

        int n = grid.size();

        if (i < 0 || i >= n || j < 0 || j >= n ||
            visited[i][j] || grid[i][j] > t) {
            return false;
        }

        visited[i][j] = true;

        if (i == n - 1 && j == n - 1) {
            return true;
        }

        for (auto &dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];

            if (possibleToReach(grid, newI, newJ, t, visited)) {
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        int left = grid[0][0];
        int right = n * n - 1;

        int result = right;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            vector<vector<bool>> visited(
                n, vector<bool>(n, false)
            );

            if (possibleToReach(grid, 0, 0, mid, visited)) {
                result = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return result;
    }
};