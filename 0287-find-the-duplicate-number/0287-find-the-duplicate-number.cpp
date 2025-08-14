class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;

        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]);
            if(nums[index] < 0){
                ans = index;
                break;
            }
            nums[index] *= -1;
        }
        return ans;
    }
};


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