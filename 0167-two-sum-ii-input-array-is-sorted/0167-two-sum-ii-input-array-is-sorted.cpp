
//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        vector<int> ans;

        while(true){
                int sum = numbers[start] + numbers[end];
                
                if(sum == target){
                    ans.push_back(start + 1);
                    ans.push_back(end + 1);
                    return ans;
                }
                else if(sum > target){
                    end--;
                }
                else if(sum < target){
                    start++;
                }            
            }
        return ans;
    }
};