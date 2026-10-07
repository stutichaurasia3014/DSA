class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int index, int leftCount, int rightCount,
               int leftRemove, int rightRemove, string curr) {

     
        if (index == s.length()) {

            if (leftRemove == 0 && rightRemove == 0 &&
                leftCount == rightCount) {

                ans.insert(curr);
            }

            return;
        }

        char ch = s[index];

        if (ch == '(') {

            
            if (leftRemove > 0) {
                solve(s, index + 1,
                      leftCount, rightCount,
                      leftRemove - 1, rightRemove,
                      curr);
            }

            solve(s, index + 1,
                  leftCount + 1, rightCount,
                  leftRemove, rightRemove,
                  curr + ch);
        }

        else if (ch == ')') {

            if (rightRemove > 0) {
                solve(s, index + 1,
                      leftCount, rightCount,
                      leftRemove, rightRemove - 1,
                      curr);
            }

        
            if (leftCount > rightCount) {
                solve(s, index + 1,
                      leftCount, rightCount + 1,
                      leftRemove, rightRemove,
                      curr + ch);
            }
        }

       
        else {
            solve(s, index + 1,
                  leftCount, rightCount,
                  leftRemove, rightRemove,
                  curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        string curr = "";

        solve(s, 0, 0, 0,
              leftRemove, rightRemove, curr);

        return vector<string>(ans.begin(), ans.end());
    }
};