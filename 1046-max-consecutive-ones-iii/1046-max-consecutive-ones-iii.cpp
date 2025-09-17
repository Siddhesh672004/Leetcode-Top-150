class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int n = nums.size();
        int left = 0, right = 0;
        int zeros = 0;

        while(right < n){
            if(nums[right] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }

            int len = right-left+1;
            maxLen = max(len, maxLen);
            
            right++;
        }

        return maxLen;        
    }
};

//Brute Force Approach
//Time Complexity: O(n^2)

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxLen = 0;
//         int n = nums.size();

//         for(int i=0; i<n; i++){
//             int zeros = 0;
//             for(int j=i; j<n; j++){
//                 if(nums[j] == 0){
//                     zeros++;
//                 }

//                 if(zeros <= k){
//                     int len = j-i+1;
//                     maxLen = max(maxLen, len);
//                 }
//             }
//         }
//         return maxLen;
//     }
// };