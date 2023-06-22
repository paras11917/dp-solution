bool fun(int i, int sum, vector<int> arr)
{
   if (sum == 0)
      return true;
   if (i == 0)
      return false;
   bool p = fun(i - 1, sum - arr[i], arr);
   bool np = fun(i - 1, sum, arr);
   return p | np;
}
bool isSubsetSum(vector<int> arr, int sum)
{
   // code here
   int n = arr.size();
   // return fun(n,sum,arr);

   vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
   for (int i = 0; i < n; i++)
   {
      dp[i][0] = true;
   }
   dp[0][arr[0]] = true;

   for (int i = 1; i < n; i++)
   {
      for (int j = 1; j <= sum; j++)
      {
         bool nt = dp[i - 1][j];
         bool take = false;
         if (j >= arr[i])
            take = dp[i - 1][j - arr[i]];
         dp[i][j] = take | nt;
      }
   }
   return dp[n - 1][sum];
}