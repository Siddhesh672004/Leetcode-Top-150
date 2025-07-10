class Solution {
public:
    //Brute Force Solution
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int left = 0;
        int right = 0;

        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                nums3.push_back(nums1[left]);
                left++;
            }
            else{
                nums3.push_back(nums2[right]);
                right++;
            }
        }

        while(left < m){
            nums3.push_back(nums1[left]);
            left++;
        }

        while(right < n){
            nums3.push_back(nums2[right]);
            right++;
        }

        int i = 0;
        while(i < n+m){
            nums1[i] = nums3[i];
            i++;
        }
    }
};