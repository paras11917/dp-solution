int FindMaxSum(int arr[], int n)
{
   // Your code here
   vector<int> dp(n + 1, INT_MIN);
   dp[0] = arr[0];
   int prev2 = arr[0];
   int prev = arr[0];
   int curr = arr[0];
   for (int i = 1; i < n; i++)
   {
      int p = arr[i];
      if (i > 1)
         p += prev2;
      int np = prev;
      curr = max(p, np);
      prev2 = prev;
      prev = curr;
   }
   return prev;
}
