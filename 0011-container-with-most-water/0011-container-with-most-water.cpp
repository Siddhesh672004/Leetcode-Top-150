//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxWater = 0;

        while(left < right){
            int width = right - left;
            int ht = min(height[left], height[right]);
            int area = width * ht;
            maxWater = max(maxWater,area);
            
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxWater = 0;

//         for(int i=0; i<height.size(); i++){
//             for(int j=i+1; j<height.size(); j++){
//                 int width = j-i;
//                 int ht = min(height[i], height[j]);
//                 int area = width * ht;
//                 maxWater = max(maxWater, area);
//             }
//         }
//         return maxWater;
//     }
// };