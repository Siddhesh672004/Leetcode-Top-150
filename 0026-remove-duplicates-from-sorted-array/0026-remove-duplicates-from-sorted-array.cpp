class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int end = 1;

        while(end < nums.size()){
            if(nums[start] != nums[end]){
                nums[start+1] = nums[end];
                start++;
                end++;
            } 
            else{
                end++;
            }
        }
        return start+1;
    }
};