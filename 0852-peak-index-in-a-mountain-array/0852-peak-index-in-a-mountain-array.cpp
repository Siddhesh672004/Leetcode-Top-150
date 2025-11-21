// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakIndex(vector<int> &arr){
        int start = 0;
        int end = arr.size()-1;

        while(start < end) {
            int mid = start + (end-start)/2;

            if(arr[mid] < arr[mid+1]) {
                start = mid + 1;
            }    
            else {
                end = mid;
            }
        }
        return start;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        return findPeakIndex(arr);
    }
};