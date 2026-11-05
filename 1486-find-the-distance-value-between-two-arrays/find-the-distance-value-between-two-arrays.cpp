class Solution {
public:
    bool valid(vector<int>& arr2, int x, int d) {
        int l = 0, r = arr2.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr2[mid] >= x - d && arr2[mid] <= x + d)
                return false;

            if (arr2[mid] < x - d)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return true;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;

        for (int x : arr1) {
            if (valid(arr2, x, d))
                ans++;
        }

        return ans;
    }
};