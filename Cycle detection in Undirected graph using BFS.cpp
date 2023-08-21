class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycleBFS(vector<int> adj[], vector<bool>&visited,int u){
        
        queue<pair<int,int>>que;
        que.push({u,-1});
        visited[u]=true;
        
        while(!que.empty()){
            pair<int,int> p = que.front();
            que.pop();
            
            int source = p.first;
            int parent = p.second;
            
            for(int &v : adj[source]){
                if(visited[v]==false){
                    que.push({v,source});
                    visited[v]=true;
                }
                else if(v!=parent){
                    return true;
                }
            }
        }
      
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        
        for(int i=0;i<V;i++){
            
            if(!visited[i] && iscycleBFS(adj,visited,i)){
                return true;
            }
        }
        return false;
    }
};
