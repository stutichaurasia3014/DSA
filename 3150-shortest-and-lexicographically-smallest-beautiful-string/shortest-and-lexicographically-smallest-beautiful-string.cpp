class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int count = 0;

        string ans = "";

        for (int j = 0; j < n; j++) {
            if (s[j] == '1')
                count++;

            while (count > k) {
                if (s[i] == '1')
                    count--;

                i++;
            }

            while (count == k && s[i] == '0') {
                i++;
            }

            if (count == k) {
                string temp = s.substr(i, j - i + 1);

                if (ans == "" ||
                    temp.length() < ans.length() ||
                    (temp.length() == ans.length() && temp < ans)) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};