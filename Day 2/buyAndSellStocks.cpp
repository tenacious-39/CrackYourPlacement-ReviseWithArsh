/* Brute Force*/
class Solution {
public:
/*
Approach: Use nested and for every element check the later elements. Among all the differences of all possible pairs choose the maximum one.
TC -> O(N^2), SC -> O(1) 
*/
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                profit = max(profit, prices[j]-prices[i]);
            }
        }
        return profit;
    }
};

/* Optimal Approach*/
class Solution {
public:
/*
Approach: Track the minimum price and track the maximum profit. The idea is to buy when the price is minimum.
TC -> O(N), SC -> O(1) 
*/
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int price = INT_MAX;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            price = min(price, prices[i]);
            profit = max(profit, prices[i]-price);
        }
        return profit;
    }
};
