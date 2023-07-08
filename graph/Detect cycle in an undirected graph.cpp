bool dfs(int i, int prev, vector<int> adj[], vector<int> &vis)
{
   vis[i] = 1;
   for (auto it : adj[i])
   {
      if (vis[it] && it != prev)
         return true;
      if (!vis[it])
      {
         if (dfs(it, i, adj, vis))
            return true;
      }
   }
}
bool bfs(int i, int prev, vector<int> adj[], vector<int> &vis, queue<pair<int, int>> &q)
{
   q.push({i, prev});
   vis[i] = 1;

   while (!q.empty())
   {
      int i = q.front().first;
      int prev = q.front().second;
      q.pop();
      for (auto it : adj[i])
      {
         if (vis[it] && it != prev)
            return true;
         if (!vis[it])
         {
            vis[it] = 1;
            q.push({it, i});
         }
      }
   }
   return false;
}
bool isCycle(int V, vector<int> adj[])
{
   // Code here
   vector<int> vis(V, 0);
   queue<pair<int, int>> q;
   for (int i = 0; i < V; i++)
   {
      if (!vis[i])
      {
         if (bfs(i, -1, adj, vis, q))
            return true;
      }
   }
   return false;
}