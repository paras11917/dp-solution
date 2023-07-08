class Solution
{
public:
   int fun(int n, vector<int> &coins, int amount)
   {
      if (n == 0)
      {
         if (amount % coins[0] == 0)
            return amount / coins[0];
         return INT_MAX;
      }
      int nt = fun(n - 1, coins, amount);
      int t = INT_MAX;
      if (coins[n] <= amount)
      {
         t = 1 + fun(n, coins, amount - coins[n]);
      }
      return min(t, nt);
   }
   int coinChange(vector<int> &coins, int amount)
   {

      int n = coins.size();
      // int ans = fun(n-1,coins,amount);
      // if(ans==INT_MAX) return -1;
      // return ans;

      vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
      for (int i = 0; i <= amount; i++)
      {
         if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
         else
            dp[0][i] = 1e9;
      }
      for (int i = 1; i < n; i++)
      {
         for (int j = 0; j <= amount; j++)
         {
            int nt = dp[i - 1][j];
            int t = 1e9;
            if (coins[i] <= j)
            {
               t = 1 + dp[i][j - coins[i]];
            }
            dp[i][j] = min(t, nt);
         }
      }
      int ans = dp[n - 1][amount];
      if (ans >= 1e9)
         return -1;
      return ans;
   }
};