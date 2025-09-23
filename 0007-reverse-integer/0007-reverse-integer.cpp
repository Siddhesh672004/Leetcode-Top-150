class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        int ans = 0;
        if(x <= INT_MIN){
            return 0;
        }

        if(x < 0){
            isNeg = true;
            x = -x;
        }
        
        while(x>0){
            if(ans > INT_MAX/10){
                return 0;
            }
            int rem = x%10;
            ans = ans*10+rem;
            x = x/10;
        }
        return isNeg ? -ans : ans;
    }
};