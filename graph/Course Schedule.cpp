class Solution
{
public:
   bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
   {
      vector<int> adj[numCourses + 1];
      for (auto x : prerequisites)
      {
         adj[x[1]].push_back(x[0]);
      }
      vector<int> vis(numCourses, 0);
      vector<int> path(numCourses, 0);
      for (int i = 0; i < numCourses; i++)
      {
         if (!vis[i])
         {
            if (!dfs(i, vis, adj, path))
               return false;
         }
      }
      return true;
   }
   bool dfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &path)
   {
      vis[i] = 1;
      path[i] = 1;
      for (auto x : adj[i])
      {
         if (!vis[x])
         {
            if (!dfs(x, vis, adj, path))
               return false;
         }
         else if (path[x])
         {
            return false;
         }
      }
      path[i] = 0;
      return true;
   }
};