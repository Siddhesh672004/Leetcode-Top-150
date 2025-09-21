//Backtracking solution DNC

class Solution {
public:
    //Remember to pass ans via &ans, because if not, the increment in fuction will not update the actual value of ans 
    void countArrangementHelper(vector<int> &v, int n, int &ans, int currNum){
        //base case
        if(currNum == n+1){
            ans++;
            return;
        }


        for(int i=1; i<=n; i++){
            if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
                v[i] = currNum;
                countArrangementHelper(v, n, ans, currNum+1);

                //Backtrack: as the ans vector is initially 0 for all indexes
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n+1);
        //As the index starts from 1
        int currNum = 1;
        int ans = 0;
        countArrangementHelper(v, n, ans, currNum);

        return ans;       
    }
};