class Solution
{
public:
   int fun(int i, int j, vector<int> &cuts)
   {
      if (i > j)
         return 0;
      int mini = 1e9;
      for (int k = i; k <= j; k++)
      {
         mini = min(mini, cuts[j + 1] - cuts[i - 1] + fun(i, k - 1, cuts) + fun(k + 1, j, cuts));
      }
      return mini;
   }
   int minCost(int n, vector<int> &cuts)
   {
      int c = cuts.size();
      cuts.push_back(n);
      cuts.push_back(0);
      sort(cuts.begin(), cuts.end());
      // return fun(1,c,cuts);

      vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
      for (int i = c; i >= 1; i--)
      {
         for (int j = i; j <= c; j++)
         {
            int mini = 1e9;
            for (int k = i; k <= j; k++)
            {
               mini = min(mini, cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
            }
            dp[i][j] = mini;
         }
      }
      return dp[1][c];
   }
};