//Time Complexity: O(n log n)
//Space Complexity: O(1)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), std::greater<int>());
        int h = 0;

        for(int i=0; i<n; i++){
            if(citations[i] >= i+1){
                h = i+1;
            }
        }
        return h;
    }
};