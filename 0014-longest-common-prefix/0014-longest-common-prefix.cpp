//Time Complexity: O(n * m)
//Space Complexity: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        // step 1: Sort the s 
        sort(strs.begin(), strs.end());

        string s1 = strs[0];
        string s2 = strs[n-1];

        for(int i=0; i<s1.length(); i++) {
            if(s1[i] != s2[i]) {
                return s1.substr(0, i);
            }
        }

        return s1;
    }
};




// //Time Complexity: O(n)
// //Space Complexity: O(n)

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string ans;
//         int i = 0;

//         while(true){
//             char curr_ch = 0;

//             for(auto str : strs){

//                 if(i >= str.size()){
//                     //Out of bound
//                     curr_ch = 0;
//                     break;
//                 }
                
//                 //Just Started
//                 if(curr_ch == 0){
//                     curr_ch = str[i];
//                 }
//                 else if(curr_ch != str[i]){
//                     curr_ch = 0;
//                     break;
//                 }
//             }
//             if(curr_ch == 0){
//                 break;
//             }
//             ans.push_back(curr_ch);
//             i++;
//         }
//         return ans;
//     }
// };