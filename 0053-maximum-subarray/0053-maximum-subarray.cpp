class Solution {
public:
    int maxSubarraySum(vector<int> &nums, int start, int end){
        //base case
        if(start == end) return nums[start];

        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;
        int mid = start + (end - start)/2;

        int maxLeftSum = maxSubarraySum(nums, start, mid);
        int maxRightSum = maxSubarraySum(nums, mid+1, end);

        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i=mid; i>=start; i--){
            leftBorderSum += nums[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }

        for(int i=mid+1; i<=end; i++){
            rightBorderSum += nums[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubarraySum(nums, 0, nums.size()-1);
    }
};






// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         long long int maxi = INT_MIN;
//         long long sum = 0;

//         for(int i=0; i<nums.size(); i++){
//             sum += nums[i];

//             if(sum > maxi){
//                 maxi = sum;
//             }

//             if(sum < 0){
//                 sum =0;
//             }
//         }

//         return maxi;
//     }
// };