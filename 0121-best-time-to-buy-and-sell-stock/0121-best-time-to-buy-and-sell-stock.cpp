class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int profit = 0;
        int minPrice = INT_MAX;

        for(int i=0; i<prices.size(); i++){
           if(prices[i] < minPrice){
            minPrice = prices[i];
           }
           profit = max(profit, prices[i] - minPrice);
        }
        return profit;









    }
};
// //
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int buy = prices[0];
//         int profit = 0;

//         for(int sell=1; sell<prices.size(); sell++){
//             if(prices[sell] > buy){
//                 profit = max(profit, prices[sell] - buy);
//             }
//             else{
//                 buy = prices[sell];
//             }
//         }      
//         return profit;
//     }
// };