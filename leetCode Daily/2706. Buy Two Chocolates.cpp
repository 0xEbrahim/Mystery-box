class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
      sort(prices.begin(), prices.end());
      int n = prices.size();
      int sum = prices[0] + prices[2 - 1];
      if(sum <= money)
        return money - sum;
      return money;
    }
};
