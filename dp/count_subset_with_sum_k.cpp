int fun(int n, int sum, int arr[])
{
   if (sum == 0)
      return 1;
   if (n == 0)
   {
      if (sum == arr[0])
         return 1;
      else
         return 0;
   }
   int t = 0;
   if (sum >= arr[n])
      t = fun(n - 1, sum - arr[n], arr);
   int nt = fun(n - 1, sum, arr);
   return t + nt;
}
int perfectSum(int arr[], int n, int sum)
{
   // Your code goes here
   // return fun(n-1,sum,arr);
   int mod = 1e9 + 7;
   vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
   for (int i = 0; i < n; i++)
   {
      dp[i][0] = 1;
   }
   if (sum >= arr[0])
   {
      if (arr[0] == 0)
         dp[0][arr[0]] = 2;
      else
         dp[0][arr[0]] = 1;
   }
   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j <= sum; j++)
      {
         int nt = dp[i - 1][j] % mod;
         int t = 0;
         if (j >= arr[i])
            t = dp[i - 1][j - arr[i]] % mod;
         dp[i][j] = t + nt;
      }
   }
   return dp[n - 1][sum] % mod;
}