vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
   // Code here
   vector<int> dp(n, 1);
   vector<int> v;
   for (int i = 0; i < n; i++)
   {
      v.push_back(i);
   }

   int maxi = 1;
   int lastindex = 1;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < i; j++)
      {
         if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
         {
            dp[i] = 1 + dp[j];
            v[i] = j;
         }
      }
      if (dp[i] > maxi)
      {
         maxi = dp[i];
         lastindex = i;
      }
   }

   vector<int> t;
   t.push_back(arr[lastindex]);
   while (v[lastindex] != lastindex)
   {
      lastindex = v[lastindex];
      t.push_back(arr[lastindex]);
   }

   reverse(t.begin(), t.end());

   return t;
}