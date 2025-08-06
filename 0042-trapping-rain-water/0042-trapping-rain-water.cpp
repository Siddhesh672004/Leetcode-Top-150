//Two Pointer Approach - Optimal Approach
//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int l = 0, r = n-1;
        int lMax = 0, rMax = 0;
        int ans = 0;

        while(l < r){
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);

            if(lMax < rMax){
                ans += (lMax - height[l]);
                l++;
            }
            else{
                ans += (rMax - height[r]);
                r--;
            }
        }
        return ans;          
    }  
}; 


//Prefix Array Approach - Better Approach
//Time Complexity: O(n)
//Space Complexity: O(n)

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> lMax(n,0);
//         vector<int> rMax(n,0);
//         lMax[0] = height[0];
//         rMax[n-1] = height[n-1];

//         for(int i=1; i<n; i++){
//             lMax[i] = max(lMax[i-1], height[i]);
//         }

//         for(int i=n-2; i>=0; i--){
//             rMax[i] = max(rMax[i+1], height[i]);
//         }

//         int ans = 0;
//         for(int i=0; i<n; i++){
//             ans += min(lMax[i], rMax[i]) - height[i];
//         }
//         return ans;
          
//     }  
// }; 

//Brute Force Approach
// Time Complexity: O(n^2)
//space Complexity: O(1);


// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int n= height.size();
//         int ans = 0;

//         for(int i=1; i<n; i++){
//             int leftMax = 0;
//             int rightMax = 0;
//             //Left max
//             for(int j=i-1; j>=0; j--){
//                 leftMax = max(leftMax, height[j]);
//             }

//             //Right Max
//             for(int k=i+1; k<n; k++){
//                 rightMax = max(rightMax, height[k]);
//             }  
//             int water = min(leftMax, rightMax) - height[i];
//             if(water  > 0) ans += water;
//         }  
//         return ans;
//     }  
// }; 

