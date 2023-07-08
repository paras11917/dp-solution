class Solution
{
public:
   int fun(int i, int j, vector<int> &nums)
   {
      if (i > j)
         return 0;
      int maxi = 0;
      for (int k = i; k <= j; k++)
      {
         maxi = max(maxi, nums[i - 1] * nums[k] * nums[j + 1] + fun(i, k - 1, nums) + fun(k + 1, j, nums));
      }
      return maxi;
   }
   int maxCoins(vector<int> &nums)
   {
      int n = nums.size();
      nums.push_back(1);
      nums.insert(nums.begin(), 1);
      // return fun(1,n,nums);

      vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
      for (int i = n; i >= 1; i--)
      {
         for (int j = i; j <= n; j++)
         {
            int maxi = 0;
            for (int k = i; k <= j; k++)
            {
               maxi = max(maxi, nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
            }
            dp[i][j] = maxi;
         }
      }
      return dp[1][n];
   }
};