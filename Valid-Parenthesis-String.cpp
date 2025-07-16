class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // minimum possible open parentheses
        int high = 0; // maximum possible open parentheses

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // '*'
                low--;      // treat '*' as ')'
                high++;     // treat '*' as '('
            }

            if (high < 0)
                return false; // too many ')'

            if (low < 0)
                low = 0; // can't have negative open
        }

        return low == 0;
    }
};
