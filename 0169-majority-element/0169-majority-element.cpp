//Optimal Solution
//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(count == 0){
                count++;
                ele = nums[i];
            }
            else if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }

        int count1 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                count1++;
            }
        }

        if(count1 > n/2){
            return ele;
        }

        return -1;
    }
};

//Better Solution 
//Time Complexity: O(n log n) + O(n)
//Space Complexity: O(n)

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         map <int, int> mp;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             mp[nums[i]]++;
//         }

//         for(auto it : mp){
//             if(it.second > n/2){
//                 return it.first;
//             }
//         }
//         return -1;
//     }
// };