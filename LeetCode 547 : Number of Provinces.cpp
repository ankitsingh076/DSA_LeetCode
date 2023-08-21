class Solution
{
    public:
        void dfs(unordered_map<int, vector < int>> &adj, vector< bool > &visited, int u)
        {
            visited[u] = true;

            for (int &v: adj[u])
            {
                if (!visited[v])
                {
                    dfs(adj, visited, v);
                }
            }
        }

    int findCircleNum(vector<vector < int>> &isConnected)
    {
        int n = isConnected.size();
        unordered_map<int, vector < int>> adj;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                count++;
            }
        }
        return count;
    }
};
