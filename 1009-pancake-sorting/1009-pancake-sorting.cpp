class Solution {
public:
    int findMax(vector<int> &arr, int i){
        int maxIndex = 0;
        for(int k=0; k<i; k++){
            if(arr[k] > arr[maxIndex]){
                maxIndex = k;
            }
        }
        return maxIndex;
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();

        for(int i=n; i>0; i--){
            int maxIndex = findMax(arr, i);

            if(maxIndex == i-1){
                continue;
            }

            res.push_back(maxIndex+1);
            reverse(arr.begin(), arr.begin() + maxIndex + 1);

            res.push_back(i);
            reverse(arr.begin(), arr.begin() + i);
        }
        return res;
    }
};