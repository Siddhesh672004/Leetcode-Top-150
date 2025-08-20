//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int n = s.length();
        int left = 0, maxLen = 0;

        for(int right=0; right<n; right++){
            if(hash[s[right]] >= left){
                left = hash[s[right]] + 1;  // move left after last duplicate
            }
            hash[s[right]] = right;  // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
   
//Time Complexity: O(n^2)
//Space Complexity: O(256)
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int maxLen = 0;

//         for(int i=0; i<n; i++){
//             int hash[250] = {0};
//             for(int j=i; j<n; j++){
//                 if(hash[s[j]] == 1) break;
//                 int len = j - i + 1;
//                 maxLen = max(len, maxLen);
//                 hash[s[j]] = 1;
//             }
//         }
//         return maxLen;
//     }
// };