class Solution
{
public:
   void solve(vector<vector<char>> &board)
   {
      int n = board.size();
      int m = board[0].size();
      vector<vector<int>> vis(n, vector<int>(m, 0));
      for (int i = 0; i < n; i++)
      {
         if (board[i][0] == 'O' && !vis[i][0])
         {
            dfs(i, 0, board, vis);
         }
      }
      for (int i = 0; i < m; i++)
      {
         if (board[0][i] == 'O' && !vis[0][i])
         {
            dfs(0, i, board, vis);
         }
      }
      for (int i = 0; i < n; i++)
      {
         if (board[i][m - 1] == 'O' && !vis[i][m - 1])
         {
            dfs(i, m - 1, board, vis);
         }
      }
      for (int i = 0; i < m; i++)
      {
         if (board[n - 1][i] == 'O' && !vis[n - 1][i])
         {
            dfs(n - 1, i, board, vis);
         }
      }
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (board[i][j] == 'O' && !vis[i][j])
            {
               board[i][j] = 'X';
            }
         }
      }
   }
   void dfs(int r, int c, vector<vector<char>> &board, vector<vector<int>> &vis)
   {
      vis[r][c] = 1;
      int n = board.size();
      int m = board[0].size();
      int rd[4] = {-1, 0, 1, 0};
      int cd[4] = {0, -1, 0, 1};
      for (int i = 0; i < 4; i++)
      {
         int row = r + rd[i];
         int col = c + cd[i];
         if (row >= 0 && row < n && col >= 0 && col < m && board[row][col] == 'O' && !vis[row][col])
         {
            dfs(row, col, board, vis);
         }
      }
   }
};