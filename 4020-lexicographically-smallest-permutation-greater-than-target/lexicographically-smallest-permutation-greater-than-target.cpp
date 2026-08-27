class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> left(26, 0);

        for (int i = 0; i < s.size(); i++) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--;
        }

        for (int i = target.size() - 1; i >= 0; i--) {
            int b = target[i] - 'a';

            left[b]++;

            bool possible = true;

            for (int x : left) {
                if (x < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            for (int j = b + 1; j < 26; j++) {
                if (left[j] > 0) {
                    left[j]--;

                    string ans = target.substr(0, i);

                    ans.push_back('a' + j);

           
                    for (int k = 0; k < 26; k++) {
                        ans.append(left[k], 'a' + k);
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};