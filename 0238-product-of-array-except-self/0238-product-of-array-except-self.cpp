// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
        vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int i=n-2; i>=0; i--){
            suffix = suffix * nums[i+1];
            ans[i] *= suffix; 
        }
       
        return ans;
    }
};


// Better Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n, 1);
//         vector<int> suffix(n, 1);
//         vector<int> ans(n, 1);

//         for(int i=1; i<n; i++){
//             prefix[i] = (prefix[i-1] * nums[i-1]);
//         }

//         for(int i=n-2; i>=0; i--){
//             suffix[i] = suffix[i+1] * nums[i+1];
//         }

//         for(int i=0; i<n; i++){
//             ans[i] = (prefix[i] * suffix[i]);
//         }

//         return ans;
//     }
// };



// Brute Force Solution
// Time Complexity: O(n²)
// Space Complexity: O(n)


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         int prod = 1;

//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(i != j){
//                     prod = prod * nums[j];
//                 }
//             }
//             ans.push_back(prod);
//             prod = 1;
//         }
//         return ans;
//     }
// };