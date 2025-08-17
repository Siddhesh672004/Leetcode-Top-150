//Time Complexity: O(n log n + n^2)
//Space Complexity: O(uniqueTriplets)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; //Optimization for duplicate values of i

            int j = i+1, k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                } 
                else if(sum > 0){
                    k--;
                } 
                else{
                    ans.push_back({ nums[i], nums[j], nums[k]});
                    j++, k--;
                    //Optimization to avoid the duplicate values of j
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};

//Time Complexity: O(n^3 * log (uniqueTriplets))
//Space Complexity: O(uniqueTriplets)
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n = nums.size();
//         set<vector<int>> s;

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 for(int k=j+1; k<n; k++){
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         vector<int> triplet = {nums[i], nums[j], nums[k]};
//                         sort(triplet.begin(), triplet.end());

//                         //Time: O(log (uniqueTriplets))
//                         if(s.find(triplet) == s.end()){
//                             s.insert(triplet);
//                             ans.push_back(triplet);
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };