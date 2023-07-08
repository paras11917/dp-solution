class Solution
{
public:
   int fun(int i, vector<int> &arr, int k)
   {
      int n = arr.size();
      if (i == n)
         return 0;
      int maxans = 0;
      int maxi = 0;
      int l = 0;
      for (int j = i; j < min(n, i + k); j++)
      {
         l++;
         maxi = max(maxi, arr[j]);
         maxans = max(maxans, maxi * l + fun(j + 1, arr, k));
      }
      return maxans;
   }
   int maxSumAfterPartitioning(vector<int> &arr, int k)
   {
      // return fun(0,arr,k);
      int n = arr.size();
      vector<int> dp(n + 1, 0);
      for (int i = n - 1; i >= 0; i--)
      {
         int maxans = 0;
         int maxi = 0;
         int l = 0;
         for (int j = i; j < min(n, i + k); j++)
         {
            l++;
            maxi = max(maxi, arr[j]);
            maxans = max(maxans, maxi * l + dp[j + 1]);
         }
         dp[i] = maxans;
      }
      return dp[0];
   }
};