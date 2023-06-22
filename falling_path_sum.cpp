class Solution
{
public:
   int fun(vector<vector<int>> &matrix, int m, int n)
   {
      if (n < 0 || n >= matrix.size())
         return 1e9;
      if (m == 0)
         return matrix[0][n];
      int l = fun(matrix, m - 1, n - 1);
      int t = fun(matrix, m - 1, n);
      int r = fun(matrix, m - 1, n + 1);
      return matrix[m][n] + min(l, min(t, r));
   }
   int minFallingPathSum(vector<vector<int>> &matrix)
   {
      int n = matrix.size();
      // int ans= INT_MAX;
      // for(int i=0;i<n;i++){
      //     ans  = min(ans,fun(matrix,n-1,0));
      // }
      // return ans;
      // vector<vector<int>> dp(n,vector<int>(n,0));
      // for(int i=0;i<n;i++){
      //     dp[0][i] = matrix[0][i];
      // }
      // for(int i=1;i<n;i++){
      //     for(int j=0;j<n;j++){
      //         int l = 1e9,r=1e9,t=1e9;
      //         if(j>0) l = dp[i-1][j-1];
      //         t = dp[i-1][j];
      //         if(j<n-1) r = dp[i-1][j+1];
      //         dp[i][j] = matrix[i][j] +  min(t,min(l,r));
      //     }
      // }
      // int ans= INT_MAX;
      // for(int i=0;i<n;i++){
      //     ans  = min(ans,dp[n-1][i]);
      // }
      // return ans;

      vector<int> prev(n, 0);
      vector<int> curr(n, 0);

      for (int i = 0; i < n; i++)
      {
         prev[i] = matrix[0][i];
      }
      for (int i = 1; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            int l = 1e9, r = 1e9, t = 1e9;
            if (j > 0)
               l = prev[j - 1];
            t = prev[j];
            if (j < n - 1)
               r = prev[j + 1];
            curr[j] = matrix[i][j] + min(t, min(l, r));
         }
         prev = curr;
      }
      int ans = INT_MAX;
      for (int i = 0; i < n; i++)
      {
         ans = min(ans, prev[i]);
      }
      return ans;
   }
};