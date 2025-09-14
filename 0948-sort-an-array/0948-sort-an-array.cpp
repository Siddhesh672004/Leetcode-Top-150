class Solution {
public:

    void merge(vector<int> &v, vector<int>& temp, int start, int mid, int end){
        int i=start, j=mid+1, k=start;
        while(i <= mid && j <= end){
            if(v[i] <= v[j]) temp[k++] = v[i++];
            else
                temp[k++] = v[j++];
        }
        while(i <= mid) temp[k++] = v[i++];
        while(j <= end) temp[k++] = v[j++];
        while(start <= end){
            v[start] = temp[start];
            start++;
        } 

    }

    void mergeSort(vector<int> &v, vector<int>& temp, int start, int end){
        if(start >= end) return;
        int mid = (start + end) >> 1;
        mergeSort(v, temp, start, mid);
        mergeSort(v, temp, mid+1, end);
        merge(v, temp, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
       vector<int> temp(nums.size(), 0);
       mergeSort(nums, temp, 0, nums.size()-1);
       return nums;
    }
};


// //Time Complexity: O(n log n)
// //Space Complexity: O(1)
// class Solution {
// public:
//     int partitionLogic(vector<int>& nums, int s, int e){
//         //Step 1: Choose pivot element
//         int pivotIndex = s;
//         int pivotElement = nums[s];

//         //Step 2: Find right position for pivot element & place it there
//         int count = 0;
//         for(int i=s+1; i<=e; i++){
//             if(nums[i] <= pivotElement){
//             count++;
//             }
//         }

//         //When we comr out of loop the rightIndex is ready
//         int rightIndex = s+count;
//         swap(nums[rightIndex], nums[pivotIndex]);
//         pivotIndex = rightIndex;

//         //Step 3: left side small and right side larger elements than pivotElement
//         int i = s;
//         int j = e;
//         while(i < pivotIndex && j > pivotIndex){
//             while(nums[i] <= pivotElement){
//             i++;
//             }

//             while(nums[j] > pivotElement){
//             j--;
//             }

//             // 2 cases
//             // A: All elements are at the right place
//             // B: Need to swap the elements
//             if(i < pivotIndex && j > pivotIndex){
//             swap(nums[i], nums[j]);
//             } 
//         }
//         return pivotIndex;
//     }

//     void quickSort(vector<int>& nums, int s, int e){
//         //Base Case
//         if(s >= e){
//             return;
//         }

//         //partition logic
//         int p = partitionLogic(nums, s, e);

//         //pivot element -> left
//         quickSort(nums, s, p-1);
        
//         //pivot element -> right
//         quickSort(nums, p+1, e);
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         vector<int> ans;
//         int n = nums.size();
//         int s = 0; 
//         int e = n-1;
//         quickSort(nums, s, e);

//         for(int i=0; i<n; i++){
//             ans.push_back(nums[i]);
//         }
//         return ans;
//     }
// };