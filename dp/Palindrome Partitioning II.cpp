class Solution
{
   bool ispalindrome(string s, int i, int e)
   {
      while (i <= e)
      {
         if (s[i++] != s[e--])
            return false;
      }
      return true;
   }
   int recursion(int ind, string s)
   {
      if (ind == s.size())
         return 0;
      int mini = 1e9;
      for (int i = ind; i < s.size(); i++)
      {
         if (ispalindrome(s, ind, i))
         {
            mini = min(mini, 1 + recursion(i + 1, s));
         }
      }
      return mini;
   }

public:
   int minCut(string s)
   {
      // return recursion(0,s)-1;

      int n = s.size();
      vector<int> dp(n + 1, 0);
      dp[n] = 0;
      for (int j = n - 1; j >= 0; j--)
      {
         int mini = 1e9;
         for (int i = j; i < s.size(); i++)
         {
            if (ispalindrome(s, j, i))
            {
               mini = min(mini, 1 + dp[i + 1]);
            }
         }
         dp[j] = mini;
      }
      return dp[0] - 1;
   }
};