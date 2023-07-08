void fun(int n, int m, vector<vector<int>> dp, vector<string> &ans, string st, string s, string t)
{
   if (n == 0 || m == 0)
   {
      ans.push_back(st);
      st = "";
      return;
   }
   if (s[n - 1] == t[m - 1])
   {
      st += s[n - 1];
      fun(n - 1, m - 1, dp, ans, st, s, t);
   }
   else
   {
      fun(n - 1, m, dp, ans, st, s, t);
      fun(n, m - 1, dp, ans, st, s, t);
   }
}
vector<string> all_longest_common_subsequences(string s, string t)
{
   // Code here
   int t1 = s.size();
   int t2 = t.size();

   vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));
   vector<string> ans;

   for (int i = 1; i <= t1; i++)
   {
      for (int j = 1; j <= t2; j++)
      {
         if (s[i - 1] == t[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
         else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
   }
   // for(auto x : dp){
   //     for(auto y : x){
   //         cout<<y<<" ";
   //     }
   //     cout<<endl;
   // }
   string st = "";

   fun(t1, t2, dp, ans, st, s, t);

   map<int, set<string>> mp;

   int mx = 0;
   for (auto x : ans)
   {
      reverse(x.begin(), x.end());
      mp[x.size()].insert(x);
   }

   for (auto x : mp)
   {
      mx = max(mx, x.first);
   }
   vector<string> an;
   for (auto x : mp[mx])
   {
      an.push_back(x);
   }
   return an;
}