class Solution
{
public:
   int findTargetSumWays(vector<int> &nums, int target)
   {
      int n = nums.size();
      int sum = 0;
      for (auto x : nums)
      {
         sum += x;
      }
      int t;

      if ((sum + target) % 2 != 0 || (sum + target) < 0)
         return 0;
      t = (sum + target) / 2;

      vector<vector<int>> dp(n, vector<int>(t + 1, 0));

      dp[0][0] = 1;
      if (nums[0] <= t)
      {
         if (nums[0] == 0)
            dp[0][nums[0]] = 2;
         else
            dp[0][nums[0]] = 1;
      }

      for (int i = 1; i < n; i++)
      {
         for (int j = 0; j <= t; j++)
         {
            int nt = dp[i - 1][j] % (int)(1e9 + 7);
            int take = 0;
            if (j >= nums[i])
               take = dp[i - 1][j - nums[i]] % (int)(1e9 + 7);
            dp[i][j] = (take + nt) % (int)(1e9 + 7);
         }
      }
      return dp[n - 1][t];
   }
};