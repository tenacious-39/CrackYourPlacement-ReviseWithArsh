class Solution {
public:
/*Approach: First find the consecutive minimum element, when we will buy the stock. Then find the consecutive maximum element at which we have to sell the stock.

Basically, consider every incresing subsequence of the array. Then we will buy ay first day and sell at last day. We will caluclate the profit for each subarray.

TC -> O(N), SC -> O(1)
*/
    int maxProfit(vector<int>& prices) {
        int maxi = prices[0], mini = prices[0];
        int p = 0, n = prices.size()-1;
        int i = 0;
        while(i < n){
            //Find the consecutiove minimum price to buy stock.
            while(i < n && prices[i+1] <= prices[i]) i++;
            mini = prices[i];

            //Find the consecutive maximum price to sell stock.
            while(i < n && prices[i+1] > prices[i]) i++;
            maxi = prices[i];

            //count the profits.
            p += maxi-mini;
        }
        return p;
    }
};
