
//Optimal Solution (Greedy Algorithm)
//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();

        while(right < n-1){
            int maxJump = 0;
            for(int i=left; i<=right; i++){
                maxJump = max(i+nums[i], maxJump);
            }

            left = right + 1;
            right = maxJump;
            jumps = jumps+1;
        }

        return jumps;
    }
};