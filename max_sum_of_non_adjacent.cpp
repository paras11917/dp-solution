int findMaxSum(int *arr, int n)
{
   // code here
   vector<int> dp(n + 1, INT_MIN);
   dp[0] = arr[0];
   for (int i = 1; i <= n; i++)
   {
      int p = arr[i];
      if (i > 1)
         p += dp[i - 2];
      int np = dp[i - 1];
      dp[i] = max(p, np);
   }
   return dp[n - 1];
}