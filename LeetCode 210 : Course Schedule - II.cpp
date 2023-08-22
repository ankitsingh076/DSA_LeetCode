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
