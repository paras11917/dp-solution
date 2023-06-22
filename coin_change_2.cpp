class Solution
{
public:
   int fun(int n, int amount, vector<int> &coins)
   {
      if (amount == 0)
         return 1;
      if (n == 0)
      {
         if (amount % coins[0] == 0)
            return 1;
         else
            return 0;
      }
      int t = 0;
      if (amount >= coins[n])
         t = fun(n, amount - coins[n], coins);
      int nt = fun(n - 1, amount, coins);
      return t + nt;
   }
   int change(int amount, vector<int> &coins)
   {
      int n = coins.size();
      // return fun(n-1,amount,coins);
      vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
      for (int i = 0; i < n; i++)
      {
         dp[i][0] = 1;
      }
      for (int i = 0; i <= amount; i++)
      {
         if (i % coins[0] == 0)
            dp[0][i] = 1;
      }
      for (int i = 1; i < n; i++)
      {
         for (int j = 1; j <= amount; j++)
         {
            int t = 0;
            if (j >= coins[i])
               t = dp[i][j - coins[i]];
            int nt = dp[i - 1][j];
            dp[i][j] = t + nt;
         }
      }
      return dp[n - 1][amount];
   }
};