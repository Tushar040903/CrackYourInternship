int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        int index = 1;

        while(index < prices.size()) {
            if(buy >= prices[index]) {
                buy = prices[index];
                index++;
            }
            else if(prices[index] > buy) {
                int currprofit = prices[index]-buy;
                profit = profit+currprofit;
                buy = prices[index++];
                //index++;
            }
        }

        return profit;
    }