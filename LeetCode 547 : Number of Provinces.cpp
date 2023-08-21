--------------------------------------------------------------------------------------Approach-01 (Using DFS & Creating adjacency list)---------------------------------------------------------------------------------------------------------------------
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


----------------------------------------------------------------------------------Approach-02 (Using DFS & without creating adjacency list)---------------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
        void dfs(vector<vector < int>> &isConnected, vector<bool> &visited, int u){
            visited[u]=true;

            for(int v=0;v<isConnected.size();v++){
                if(!visited[v] && isConnected[u][v]){
                    dfs(isConnected,visited,v);
                }
            }
        }

        int findCircleNum(vector<vector < int>> &isConnected)
        {
            int n = isConnected.size();
            vector<bool> visited(n, false);

            int count = 0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    dfs(isConnected,visited,i);
                    count++;
                }
            }
            return count;
        }
};


----------------------------------------------------------------------------------Approach-03 (Using BFS & without creating adjacency list)-------------------------------------------------------------------------------------
class Solution
{
    public:
        int n;
        void bfs(vector<bool> &visited, vector<vector< int>> &isConnected, int u)
        {
            queue<int> que;
            que.push(u);
            visited[u] = true;
    
            while (!que.empty())
            {
                int u = que.front();
                que.pop();
    
                for (int v = 0; v < n; v++)
                {
                    if (!visited[v] && isConnected[u][v])
                    {
                        que.push(v);
                        visited[v] = true;
                    }
                }
            }
        }

        int findCircleNum(vector<vector < int>> &isConnected)
        {
            n = isConnected.size();
    
            vector<bool> visited(n, false);
            int count = 0;
    
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    bfs(visited, isConnected, i);
                    count++;
                }
            }
    
            return count;
        }
};
