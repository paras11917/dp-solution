int fun(int i, int j, int isTrue, string S, vector<vector<vector<int>>> &dp)
{
   if (i > j)
      return 0;
   if (i == j)
   {
      if (isTrue)
         return S[i] == 'T';
      else
         return S[i] == 'F';
   }
   if (dp[i][j][isTrue] != -1)
      return dp[i][j][isTrue];
   int ways = 0;
   for (int k = i + 1; k < j; k += 2)
   {
      int lt = fun(i, k - 1, 1, S, dp);
      int rt = fun(k + 1, j, 1, S, dp);
      int lf = fun(i, k - 1, 0, S, dp);
      int rf = fun(k + 1, j, 0, S, dp);
      if (S[k] == '&')
      {
         if (isTrue)
         {
            ways += (rt * lt) % 1003;
         }
         else
         {
            ways += (rf * lt) % 1003 + (rt * lf) % 1003 + (rf * lf) % 1003;
         }
      }
      else if (S[k] == '|')
      {
         if (isTrue)
         {
            ways += (rf * lt) % 1003 + (rt * lf) % 1003 + (rt * lt) % 1003;
         }
         else
         {
            ways += (rf * lf) % 1003;
         }
      }
      else
      {
         if (isTrue)
         {
            ways += (rf * lt) % 1003 + (rt * lf) % 1003;
         }
         else
         {
            ways += (rt * lt) % 1003 + (rf * lf) % 1003;
         }
      }
   }
   return dp[i][j][isTrue] = ways % 1003;
}
int countWays(int N, string S)
{
   // code here
   vector<vector<vector<int>>> dp(N + 2, vector<vector<int>>(N + 2, vector<int>(2, -1)));
   return fun(0, N - 1, 1, S, dp);
}