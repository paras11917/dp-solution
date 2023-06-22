int fun(vector<vector<int>> &points, int day, int last)
{
   if (day == 0)
   {
      int maxi = 0;
      for (int i = 0; i < 3; i++)
      {
         if (i != last)
         {
            maxi = max(maxi, points[day][i]);
         }
      }
      return maxi;
   }
   int maxi = 0;
   for (int i = 0; i < 3; i++)
   {
      if (i != last)
      {
         int acti = points[day][i] + fun(points, day - 1, i);
         maxi = max(maxi, acti);
      }
   }
   return maxi;
}
int maximumPoints(vector<vector<int>> &points, int n)
{
   // Code here

   vector<int> curr(4, 0);
   vector<int> prev(4, 0);
   for (int i = 0; i < 4; i++)
   {
      int maxi = 0;
      for (int j = 0; j < 3; j++)
      {
         if (i != j)
         {
            maxi = max(maxi, points[0][j]);
         }
         prev[i] = maxi;
      }
   }

   for (int k = 1; k < n; k++)
   {
      for (int last = 0; last < 4; last++)
      {
         for (int j = 0; j < 3; j++)
         {
            if (last != j)
            {
               curr[last] = max(curr[last], points[k][j] + prev[j]);
            }
         }
      }
      prev = curr;
   }
   return prev[3];
}