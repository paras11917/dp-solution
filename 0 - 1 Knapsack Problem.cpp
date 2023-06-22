int fun(int W, int wt[], int val[], int n)
{
   if (n == 0)
   {
      if (wt[0] <= W)
         return val[0];
      else
         return 0;
   }
   int t = 0;
   if (W >= wt[n])
      t = val[n] + fun(W - wt[n], wt, val, n - 1);
   int nt = fun(W, wt, val, n - 1);
   return max(t, nt);
}
int knapSack(int W, int wt[], int val[], int n)
{
   // Your code here

   //   return fun(W,wt,val,n);

   vector<vector<int>> dp(n, vector<int>(W + 1, 0));
   for (int i = wt[0]; i <= W; i++)
      dp[0][i] = val[0];
   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j <= W; j++)
      {
         int t = 0;
         if (wt[i] <= j)
            t = val[i] + dp[i - 1][j - wt[i]];
         int nt = dp[i - 1][j];
         dp[i][j] = max(t, nt);
      }
   }

   return dp[n - 1][W];
}