class Solution
{
public:
   int fun(int m, int n)
   {
      if (m == 0 && n == 0)
         return 1;
      if (m < 0 || n < 0)
         return 0;
      return fun(m, n - 1) + fun(m - 1, n);
   }
   int uniquePaths(int m, int n)
   {
      // return fun(m-1,n-1);
      // vector<vector<int>> dp(m,vector<int>(n,0));

      // for(int i=0;i<m;i++){
      //     for(int j=0;j<n;j++){
      //         if(i==0 || j==0) dp[i][j] = 1;
      //         else dp[i][j] = dp[i-1][j] + dp[i][j-1];
      //     }
      // }
      // return dp[m-1][n-1];

      vector<int> prev(n, 0);
      vector<int> curr(n, 0);

      for (int i = 0; i < m; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (i == 0 || j == 0)
               curr[j] = 1;
            else
               curr[j] = prev[j] + curr[j - 1];
         }
         prev = curr;
      }
      return prev[n - 1];
   }
};