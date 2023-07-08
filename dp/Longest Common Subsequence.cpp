class Solution
{
public:
   int fun(int t1, int t2, string text1, string text2)
   {
      if (t1 < 0 || t2 < 0)
         return 0;
      if (text1[t1] == text2[t2])
         return 1 + fun(t1 - 1, t2 - 1, text1, text2);
      return max(fun(t1 - 1, t2, text1, text2), fun(t1, t2 - 1, text1, text2));
   }
   int longestCommonSubsequence(string text1, string text2)
   {
      int t1 = text1.size();
      int t2 = text2.size();
      // return fun(t1-1,t2-1,text1,text2);

      vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));

      for (int i = 1; i <= t1; i++)
      {
         for (int j = 1; j <= t2; j++)
         {
            if (text1[i - 1] == text2[j - 1])
               dp[i][j] = 1 + dp[i - 1][j - 1];
            else
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
      return dp[t1][t2];
   }
};