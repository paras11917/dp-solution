class Solution
{
public:
   int fun(int n, int buy, int k, vector<int> &prices)
   {
      if (k == 0 || n == prices.size())
         return 0;
      if (buy)
      {
         return max(-prices[n] + fun(n + 1, 0, k, prices), fun(n + 1, 1, k, prices));
      }
      return max(prices[n] + fun(n + 1, 1, k - 1, prices), fun(n + 1, 0, k, prices));
   }
   int maxProfit(int k, vector<int> &prices)
   {
      int n = prices.size();
      // return fun(0,1,k,prices);
      vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
      for (int i = n - 1; i >= 0; i--)
      {
         for (int j = 0; j <= 1; j++)
         {
            for (int z = 1; z <= k; z++)
            {
               if (j == 1)
               {
                  dp[i][j][z] = max(-prices[i] + dp[i + 1][0][z], dp[i + 1][1][z]);
               }
               else
               {
                  dp[i][j][z] = max(prices[i] + dp[i + 1][1][z - 1], dp[i + 1][0][z]);
               }
            }
         }
      }
      return dp[0][1][k];
   }
};