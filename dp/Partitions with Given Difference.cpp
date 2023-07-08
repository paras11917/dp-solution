int countPartitions(int n, int d, vector<int> &arr)
{
   // Code here
   int sum = 0;
   for (auto x : arr)
   {
      sum += x;
   }
   if ((sum + d) % 2 != 0)
      return 0;
   int target = (sum + d) / 2;

   vector<vector<int>> dp(n, vector<int>(target + 1, 0));

   dp[0][0] = 1;
   if (arr[0] <= target)
   {
      if (arr[0] == 0)
         dp[0][arr[0]] = 2;
      else
         dp[0][arr[0]] = 1;
   }

   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j <= target; j++)
      {
         int nt = dp[i - 1][j] % (int)(1e9 + 7);
         int take = 0;
         if (j >= arr[i])
            take = dp[i - 1][j - arr[i]] % (int)(1e9 + 7);
         dp[i][j] = (take + nt) % (int)(1e9 + 7);
      }
   }
   return dp[n - 1][target];
}