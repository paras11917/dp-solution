void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
   vis[node] = 1;
   for (auto it : adj[node])
   {
      if (!vis[it])
         dfs(it, vis, st, adj);
   }
   st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
   // code here
   // 	    vector<int> vis(V,0);
   // 		stack<int> st;
   // 		for (int i = 0; i < V; i++) {
   // 			if (!vis[i]) {
   // 				dfs(i, vis, st, adj);
   // 			}
   // 		}

   // 		vector<int> ans;
   // 		while (!st.empty()) {
   // 			ans.push_back(st.top());
   // 			st.pop();
   // 		}
   // 		return ans;

   vector<int> indegree(V, 0);
   for (int i = 0; i < V; i++)
   {
      for (auto it : adj[i])
      {
         indegree[it]++;
      }
   }

   queue<int> q;
   for (int i = 0; i < V; i++)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }

   vector<int> topo;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      topo.push_back(node);

      for (auto it : adj[node])
      {
         indegree[it]--;
         if (indegree[it] == 0)
            q.push(it);
      }
   }

   return topo;
}