//DNC Solution, using backtracking

class Solution {
public:
    void permuteUniqueHelper(vector<int>& nums, vector<vector<int>> & ans, int start){
        //base case
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        //use map to avoid duplication, marl the nums[i] = visited;
        unordered_map<int, bool> visited;
        for(int i=start; i<nums.size(); i++){
            //If the nums[i] is already visited then skip the element
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            //If the element is unique then mark as visited
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            permuteUniqueHelper(nums, ans, start+1);

            //backtrack
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int start = 0;
        permuteUniqueHelper(nums, ans, start);

        return ans;
    }
};