// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for(int i=0; i<s.length(); i++) {
            // If current character is ')', decrease depth first
            // This helps detect outermost closing bracket
            if(s[i] == ')') count--;

            // count > 0 means we are inside inner parentheses
            if(count != 0) ans += s[i];

            // This helps detect outermost opening bracket
            if(s[i] == '(') count++;
        }
        return ans;
    }
};