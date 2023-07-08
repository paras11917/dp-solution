class Solution
{
public:
   int fun(int i, int buy, vector<int> &prices)
   {
      if (i == prices.size())
         return 0;
      if (buy)
      {
         return max(-prices[i] + fun(i + 1, 0, prices), fun(i + 1, 1, prices));
      }
      return max(prices[i] + fun(i + 1, 1, prices), fun(i + 1, 0, prices));
   }
   int maxProfit(vector<int> &prices)
   {
      // return fun(0,1,prices);
      int n = prices.size();
      vector<vector<int>> dp(n + 1, vector<int>(2, 0));
      dp[n][0] = dp[n][1] = 0;
      for (int i = n - 1; i >= 0; i--)
      {
         for (int j = 0; j <= 1; j++)
         {
            if (j)
            {
               dp[i][j] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else
            {
               dp[i][j] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
            }
         }
      }
      return dp[0][1];
   }
};