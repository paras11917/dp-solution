int minimizeCost(vector<int> &height, int n, int k)
{
   // Code here
   vector<int> dp(n + 1, INT_MAX);
   dp[0] = 0;
   dp[1] = 0;
   dp[2] = abs(height[1] - height[0]);
   for (int i = 3; i <= n; i++)
   {
      for (int j = 1; j <= k; j++)
      {
         if (i > j)
            dp[i] = min(dp[i - j] + abs(height[i - 1] - height[i - 1 - j]), dp[i]);
      }
   }
   return dp[n];
}