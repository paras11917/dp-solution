class Solution
{
public:
   bool canPartition(vector<int> &nums)
   {
      int n = nums.size();
      if (n == 1)
         return false;

      int sum = 0;
      for (auto x : nums)
      {
         sum += x;
      }
      if (sum % 2 != 0)
         return false;
      sum /= 2;

      // vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
      vector<bool> prev(sum + 1, 0);
      vector<bool> curr(sum + 1, 0);

      prev[0] = curr[0] = true;

      if (nums[0] <= sum)
         prev[nums[0]] = true;

      for (int i = 1; i < n; i++)
      {
         for (int j = 1; j <= sum; j++)
         {
            bool nt = prev[j];
            bool take = false;
            if (j >= nums[i])
               take = prev[j - nums[i]];
            curr[j] = take | nt;
         }
         prev = curr;
      }
      return prev[sum];
   }
};