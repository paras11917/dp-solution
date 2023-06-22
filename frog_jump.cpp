int fun(vector<int> &height, int n)
{
   if (n < 0)
      return INT_MAX;
   if (n == 0)
      return 0;
   int l = INT_MAX, r = INT_MAX;
   l = fun(height, n - 1) + abs(height[n] - height[n - 1]);
   if (n > 1)
      r = fun(height, n - 2) + abs(height[n] - height[n - 2]);
   return min(l, r);
}
int minimumEnergy(vector<int> &height, int n)
{
   // return fun(height,n-1);
   // Code here
   // vector<int> dp(n+1,0);
   // dp[0]=0;
   // dp[1]=abs(height[1] - height[0]);

   // for(int i=2;i<=n;i++){
   //     dp[i] = min(dp[i-1] + abs(height[i] - height[i-1]) ,dp[i-2] + abs(height[i] - height[i-2]));
   // }
   // return dp[n-1];

   int prev2 = 0;
   int prev = abs(height[1] - height[0]);

   for (int i = 2; i <= n; i++)
   {
      int curr = min(prev + abs(height[i] - height[i - 1]), prev2 + abs(height[i] - height[i - 2]));
      prev2 = prev;
      prev = curr;
   }
   return prev2;
}