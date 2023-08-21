------------------------------------------------------------------------------------------Approach-01 (Using DFS)--------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
        int n;

    bool dfs(unordered_map<int, vector < int>> &adj, vector<bool> &visited, vector<bool> &inRecursion, int u){
        visited[u]=true;
        inRecursion[u]=true;

        for(int &v:adj[u]){
            if(visited[v]==true){
                if(inRecursion[v]==true){
                    return true;
                }
            }
            else {
                if(dfs(adj,visited,inRecursion,v)==true){
                    return true;
                }
            }
        }
        inRecursion[u]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector < int>> &prerequisites)
    {
        n = prerequisites.size();

        unordered_map<int, vector < int>> adj;
        for (int i = 0; i < n; i++)
        {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<bool>visited(numCourses, false);
        vector<bool>inRecursion(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(adj,visited,inRecursion,i)){
                return false;
            }
        }

        return true;
    }
};

------------------------------------------------------------------------------------------Approach-02 (Using BFS)--------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
        int n;
    bool canFinish(int numCourses, vector<vector < int>> &prerequisites)
    {
        n = prerequisites.size();

        unordered_map<int, vector < int>> adj;
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < n; i++)
        {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            indegree[v]++;

            adj[u].push_back(v);
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

        if(count==numCourses){
            return true;
        }
        return false;
    }
};
