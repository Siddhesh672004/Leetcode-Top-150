class Solution {
public:
int lastOccurence(vector<int> arr, int n, int target){
    //3 Steps
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int temp = -1;
    
    while(start <= end){
        //1st Condition
        if(arr[mid] == target){
            temp = mid;
            start = mid + 1;
        }
        //2nd Condition --> Right Half
        else if(target > arr[mid]){
            start = mid + 1;
        }
        //3rd Condition --> Left Half
        else if(target < arr[mid]){
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return temp;
}


int firstOccurence(vector<int> arr, int n, int target){
    //3 Steps
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int temp = -1;
    
    while(start <= end){
        //1st Condition
        if(arr[mid] == target){
            temp = mid;
            end = mid - 1;
        }
        //2nd Condition --> Right Half
        else if(target > arr[mid]){
            start = mid + 1;
        }
        //3rd Condition --> Left Half
        else if(target < arr[mid]){
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    
    return temp;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int size = nums.size();

        ans.push_back(firstOccurence(nums, size, target));
        ans.push_back(lastOccurence(nums, size, target));

        return ans;
    }
};