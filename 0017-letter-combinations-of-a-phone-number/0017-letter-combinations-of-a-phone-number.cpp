class Solution {
public:
    void solve(string digits, int index, string output, vector<string> &ans, vector<string> &mp){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        //solve one case
        int digit = digits[index] - '0';
        string value = mp[digit];

        for(int i=0; i<value.length(); i++){
            char ch = value[i];
            output.push_back(ch);
            //recursive call
            solve(digits, index+1, output, ans, mp);

            //backtrack
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }

        vector<string> mp(10);
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        int index  = 0;
        string output = "";
        //function call
        solve(digits, index, output, ans, mp);

        return ans;       
    }
};