class Solution
{
public:
   vector<int> eventualSafeNodes(vector<vector<int>> &graph)
   {
      vector<int> adjrev[graph.size()];
      vector<int> indegree(graph.size(), 0);
      for (int i = 0; i < graph.size(); i++)
      {
         for (int j = 0; j < graph[i].size(); j++)
         {
            adjrev[graph[i][j]].push_back(i);
            indegree[i]++;
         }
      }

      queue<int> q;
      for (int i = 0; i < graph.size(); i++)
      {
         if (indegree[i] == 0)
            q.push(i);
      }

      vector<int> ans;
      while (!q.empty())
      {
         int node = q.front();
         q.pop();
         ans.push_back(node);
         for (auto it : adjrev[node])
         {
            indegree[it]--;
            if (indegree[it] == 0)
               q.push(it);
         }
      }
      sort(ans.begin(), ans.end());
      return ans;
   }
};