class Solution
{
public:
   string shortestCommonSupersequence(string str1, string str2)
   {
      int t1 = str1.size();
      int t2 = str2.size();
      // return fun(t1-1,t2-1,text1,text2);

      vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));

      for (int i = 1; i <= t1; i++)
      {
         for (int j = 1; j <= t2; j++)
         {
            if (str1[i - 1] == str2[j - 1])
               dp[i][j] = 1 + dp[i - 1][j - 1];
            else
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
      string ans = "";
      int i = t1, j = t2;
      while (i > 0 && j > 0)
      {
         if (str1[i - 1] == str2[j - 1])
         {
            ans += str1[i - 1];
            i--;
            j--;
         }
         else
         {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
               ans += str1[i - 1];
               i--;
            }
            else
            {
               ans += str2[j - 1];
               j--;
            }
         }
      }
      while (i > 0)
      {
         ans += str1[i - 1];
         i--;
      }
      while (j > 0)
      {
         ans += str2[j - 1];
         j--;
      }
      reverse(ans.begin(), ans.end());
      return ans;
   }
};