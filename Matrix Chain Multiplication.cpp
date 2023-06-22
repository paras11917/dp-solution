int fun(int i, int j, int arr[])
{
   if (i == j)
      return 0;
   int steps = INT_MAX;
   for (int k = i; k < j; k++)
   {
      steps = min(steps, arr[i - 1] * arr[j] * arr[k] + fun(i, k, arr) + fun(k + 1, j, arr));
   }
   return steps;
}
int matrixMultiplication(int N, int arr[])
{
   // code here
   // return fun(1,N-1,arr);
   vector<vector<int>> dp(N, vector<int>(N, 0));
   for (int i = N - 1; i >= 0; i--)
   {
      for (int j = i + 1; j < N; j++)
      {
         int mini = INT_MAX;
         for (int k = i; k < j; k++)
         {
            mini = min(mini, arr[i - 1] * arr[j] * arr[k] + dp[i][k] + dp[k + 1][j]);
         }
         dp[i][j] = mini;
      }
   }
   return dp[1][N - 1];
}