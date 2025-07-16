class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int end = 1;
        int count = 0;

        while(end < nums.size()){
            if(nums[start] != nums[end]){
                nums[start+1] = nums[end];
                start++;
                end++;
                count++;
            } 
            else{
                end++;
            }
        }
        return count+1;
    }
};