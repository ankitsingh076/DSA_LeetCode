class Solution{
  public:
  bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
        queue<int>que;
        
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        
        int nodesCount=0;
        for(int u=0;u<V;u++){
            if(indegree[u]==0){
                que.push(u);
                nodesCount++;
                
            }
        }
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(int &v:adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0){
                    que.push(v);
                    nodesCount++;
                }
            }
        }
        
        if(nodesCount==V) return false;
        return true;
    }
};
