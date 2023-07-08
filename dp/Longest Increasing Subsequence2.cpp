int longestSubsequence(int n, int a[])
{
   // your code here
   vector<int> tmp;
   tmp.push_back(a[0]);
   for (int i = 1; i < n; i++)
   {
      if (a[i] > tmp.back())
      {
         tmp.push_back(a[i]);
      }
      else
      {
         int ind = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
         tmp[ind] = a[i];
      }
   }
   return tmp.size();
}