class Solution
{
public:
   static bool comp(string &s1, string &s2)
   {
      return s1.size() < s2.size();
   }

   bool compare(string s1, string s2)
   {
      if ((s1.size() + 1) != s2.size())
         return false;
      int f = 0, s = 0;
      while (s < s2.size())
      {
         if (s1[f] == s2[s])
         {
            f++;
            s++;
         }
         else
         {
            s++;
         }
      }
      if (f == (s1.size()) && s == (s2.size()))
         return true;
      return false;
   }

   int longestStrChain(vector<string> &words)
   {
      int n = words.size();
      vector<int> dp(n, 1);

      sort(words.begin(), words.end(), comp);
      int maxi = 1;

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < i; j++)
         {
            if (compare(words[j], words[i]) && 1 + dp[j] > dp[i])
            {
               dp[i] = 1 + dp[j];
            }
         }
         if (dp[i] > maxi)
         {
            maxi = dp[i];
         }
      }
      return maxi;
   }
};