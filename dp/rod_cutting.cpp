int cutRod(int price[], int n)
{
   // code here
   vector<vector<int>> dp(n, vector<int>(n + 1, 0));
   for (int i = 1; i <= n; i++)
      dp[0][i] = price[0] * i;
   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j <= n; j++)
      {
         int t = 0;
         if (i + 1 <= j)
            t = price[i] + dp[i][j - i - 1];
         int nt = dp[i - 1][j];
         dp[i][j] = max(t, nt);
      }
   }
   return dp[n - 1][n];
}