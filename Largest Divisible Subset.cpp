class Solution
{
public:
   vector<int> largestDivisibleSubset(vector<int> &nums)
   {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<int> dp(n, 1);
      vector<int> v;
      for (int i = 0; i < n; i++)
      {
         v.push_back(i);
      }

      int maxi = 1;
      int lastindex = 0;

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < i; j++)
         {
            if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
            {
               dp[i] = 1 + dp[j];
               v[i] = j;
            }
         }
         if (dp[i] > maxi)
         {
            maxi = dp[i];
            lastindex = i;
         }
      }

      vector<int> temp;
      temp.push_back(nums[lastindex]);
      while (v[lastindex] != lastindex)
      {
         lastindex = v[lastindex];
         temp.push_back(nums[lastindex]);
      }
      sort(temp.begin(), temp.end());
      return temp;
   }
};