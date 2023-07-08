class Solution
{
public:
   vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
   {
      vector<int> adj[numCourses + 1];
      for (auto x : prerequisites)
      {
         adj[x[1]].push_back(x[0]);
      }
      vector<int> vis(numCourses, 0);
      stack<int> ans;
      vector<int> path(numCourses, 0);
      for (int i = 0; i < numCourses; i++)
      {
         if (!vis[i])
         {
            vector<int> a;
            if (!dfs(i, vis, adj, path, ans))
               return a;
         }
      }
      vector<int> v;
      while (!ans.empty())
      {
         v.push_back(ans.top());
         ans.pop();
      }
      return v;
   }
   bool dfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &path, stack<int> &ans)
   {
      vis[i] = 1;
      path[i] = 1;
      for (auto x : adj[i])
      {
         if (!vis[x])
         {
            if (!dfs(x, vis, adj, path, ans))
               return false;
         }
         else if (path[x])
         {
            return false;
         }
      }
      ans.push(i);
      path[i] = 0;
      return true;
   }
};