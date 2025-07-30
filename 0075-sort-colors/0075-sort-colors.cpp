class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int r = nums.size()-1;

        while(m <= r){
            if(nums[m] == 0){
                swap(nums[m], nums[l]);
                l++;
                m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m], nums[r]);
                r--;
            }
        }
    }
};



























// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         // sort(nums.begin(), nums.end());

//         //Time Complexity: O(n)
//         //Space Complexity: O(1)

//         int zeros = 0;
//         int ones = 0;
//         int twos = 0;

//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == 0){
//                 zeros++;
//             }
//             else if(nums[i] == 1){
//                 ones++;
//             }
//             else{
//                 twos++;
//             }
//         }

//         int i=0;
//         while(zeros--){
//             nums[i] = 0;
//             i++;
//         }

//         while(ones--){
//             nums[i] = 1;
//             i++;
//         }

//         while(twos--){
//             nums[i] = 2;
//             i++;
//         }
//     }
// };