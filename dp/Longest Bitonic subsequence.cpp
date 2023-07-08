int LongestBitonicSequence(vector<int> nums)
{
   // code here
   int n = nums.size();
   int maxi = 1;
   vector<int> dp(n, 1);
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < i; j++)
      {
         if (nums[i] > nums[j])
         {
            dp[i] = max(dp[i], 1 + dp[j]);
         }
      }
   }
   vector<int> dp2(n, 1);
   for (int i = n - 1; i >= 0; i--)
   {
      for (int j = n - 1; j > i; j--)
      {
         if (nums[i] > nums[j])
         {
            dp2[i] = max(dp2[i], 1 + dp2[j]);
         }
      }
   }
   for (int i = 0; i < n; i++)
   {
      maxi = max(maxi, dp[i] + dp2[i]);
   }
   return maxi - 1;
   // comment
}