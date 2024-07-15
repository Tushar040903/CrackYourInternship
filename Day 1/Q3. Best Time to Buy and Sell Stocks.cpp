int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int index = 1;
        int profit = 0;
        while(index < prices.size()) {
            if(buy > prices[index]) {
                buy = prices[index];
            }
            else {
                int currprofit = prices[index] - buy;
                profit = max(profit,currprofit);
                
            }
            index++;
        }

        return profit;
    }