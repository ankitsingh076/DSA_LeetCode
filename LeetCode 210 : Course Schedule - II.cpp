--------------------------------------------------------------------------------Approach-01 (using BFS)------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
        vector<int> findOrder(int numCourses, vector<vector < int>> &prerequisites)
        {
            vector<int> result;
            unordered_map<int, vector < int>> adj;

            vector<int> indegree(numCourses, 0);

            for (int i = 0; i < prerequisites.size(); i++)
            {
                int u = prerequisites[i][1];
                int v = prerequisites[i][0];

                adj[u].push_back(v);
                indegree[v]++;
            }

            queue<int> que;
            int count = 0;
            for (int i = 0; i < numCourses; i++)
            {
                if (indegree[i] == 0)
                {
                    que.push(i);
                    count++;
                }
            }

            while (!que.empty())
            {
                int u = que.front();
                result.push_back(u);
                que.pop();

                for (int &v: adj[u])
                {
                    indegree[v]--;

                    if (indegree[v] == 0)
                    {
                        que.push(v);
                        count++;
                    }
                }
            }

            if (numCourses == count)
            {
                return result;
            }

            return {};
        }
};


--------------------------------------------------------------------------------Approach-02 (using DFS)------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
       	// Using DFS
        bool hasCycle = false;

    void dfs(unordered_map<int, vector < int>> &adj, int u, vector< bool > &visited, vector< bool > &inRecursion, stack< int > &st)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v: adj[u])
        {
            if (!visited[v])
            {
                dfs(adj, v, visited, inRecursion, st);
            }
            else if (inRecursion[v] == true)
            {
                hasCycle = true;
                return;
            }
        }
        inRecursion[u] = false;
        st.push(u);
    }

    vector<int> findOrder(int numCourses, vector<vector < int>> &prerequisites)
    {

        unordered_map<int, vector < int>> adj;

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        stack<int> st;

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i, visited, inRecursion, st);
            }
        }

        if (hasCycle)
        {
            return {};
        }
        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
