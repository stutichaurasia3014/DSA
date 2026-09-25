class Solution {
public:

    // Parses expression until '}'
    set<string> parseExpression(string &s, int &i) {
        set<string> result = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','

            set<string> next = parseTerm(s, i);

            // Union
            for (string str : next) {
                result.insert(str);
            }
        }

        return result;
    }

    // Parses concatenated parts
    set<string> parseTerm(string &s, int &i) {
        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> current;

            if (s[i] == '{') {
                i++; // skip '{'

                current = parseExpression(s, i);

                i++; // skip '}'
            }
            else {
                current.insert(string(1, s[i]));
                i++;
            }

            // Concatenation
            set<string> temp;

            for (string a : result) {
                for (string b : current) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parseExpression(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};