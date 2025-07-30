//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        while(nums[0] != nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }

        return nums[0];
    }
};




//Time Complexity: O(n)
//Space Complexity: O(1)

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//         int ans;

//         for(int i=0; i<nums.size(); i++){
//             int index = abs(nums[i]);
//             if(nums[index] < 0){
//                 ans = index;
//                 break;
//             }

//             nums[index] *= -1;
//         }
//         return ans;
//     }
// };







// //Time Complexity: O(n log n)
// //Space Complexity: O(n)

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         for(int i=0; i<nums.size()-1; i++){
//             if(nums[i] == nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };