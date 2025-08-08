//Optimal Approach 
//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.size()-1;

        while(s[i] == ' ' && i>= 0){
            i--;
        }

        while(i >= 0 && s[i] != ' '){
            count++;
            i--;
        }
        return count;        
    }
};