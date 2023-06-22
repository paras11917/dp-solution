class Solution
{
public:
   int fun(int n, int prevind, vector<int> &nums)
   {
      if (n == nums.size())
         return 0;
      int nt = fun(n + 1, prevind, nums);
      int t = 0;
      if (prevind == -1 || nums[prevind] < nums[n])
      {
         t = 1 + fun(n + 1, n, nums);
      }
      return max(t, nt);
   }
   int lengthOfLIS(vector<int> &nums)
   {
      int n = nums.size();
      // return fun(0,-1,nums);

      // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      // for(int i=n-1;i>=0;i--){
      //     for(int prevind=i-1;prevind>=-1;prevind--){
      //         int nt = dp[i+1][prevind+1];
      //         int t=0;
      //         if(prevind==-1 || nums[prevind]<nums[i]){
      //             t = 1+ dp[i+1][i+1];
      //         }
      //          dp[i][prevind+1] = max(t,nt);
      //     }
      // }
      // return dp[0][0];

      vector<int> dp(n, 1);
      int maxi = 1;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < i; j++)
         {
            if (nums[i] > nums[j])
               dp[i] = max(dp[i], 1 + dp[j]);
         }
         maxi = max(maxi, dp[i]);
      }
      return maxi;
   }
};