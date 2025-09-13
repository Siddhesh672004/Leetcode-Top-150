class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> bottomLeftDiagonalCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans){
        vector<string> temp;

        for(int row=0; row<n; row++){
            string output = "";
            for(int col=0; col<n; col++){
                output.push_back(board[row][col]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    //bool isSafe TIME COMPLEXITY: O(1) as we are using map
    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        if(rowCheck[row] == true)
            return false;

        if(upperLeftDiagonalCheck[col-row] == true)
            return false;

        if(bottomLeftDiagonalCheck[row+col] == true)
            return false;

        return true;
    } 

    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans){
        //base case
        if(col >= n){
            storeSolution(board, n, ans);
            return;
        }

        //Solve 1 case, rest recursion will handle
        for(int row=0; row<n; row++){
            //If the queen is safe 
            if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[col-row] = true;
            bottomLeftDiagonalCheck[col+row] = true;

            //Recursive call
            solve(board, col+1, n, ans);

            //backtracking
            board[row][col] = '.';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[col-row] = false;
            bottomLeftDiagonalCheck[col+row] = false;

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<vector<char>> board(n, vector<char> (n, '.'));
      int col = 0;

      // '-' means empty cell
      // 'Q' means Queen is present at cell
      solve(board, col, n, ans);

      return ans;
    }
};