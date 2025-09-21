class Solution {
public:
    void solve(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index){
        //base case
        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            //Preventing the same element to be picked again
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            solve(candidates, target-candidates[i], v, ans, i+1);
            //backtrack
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates, target, v, ans, 0);

        return ans;
    }
};



//Can be a solution, but memory limit exceed
// class Solution {
// public:
//     void solve(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index){
//         //base case
//         if(target == 0){
//             ans.push_back(v);
//             return;
//         }

//         if(target < 0){
//             return;
//         }

//         for(int i=index; i<candidates.size(); i++){
//             v.push_back(candidates[i]);
//             solve(candidates, target-candidates[i], v, ans, i+1);
//             //backtrack
//             v.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans;
//         vector<int> v;
//         solve(candidates, target, v, ans, 0);

//         //Removing the duplicates from vector
//         set<vector<int>> st;
//         for(auto i: ans){
//             st.insert(i);
//         }
//         //Clean the ans vector and re-insert the unique elements only
//         ans.clear();
//         for(auto i: st){
//             ans.push_back(i);
//         }

//         return ans;
//     }
// };