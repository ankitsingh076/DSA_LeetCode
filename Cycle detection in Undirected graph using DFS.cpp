class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycleDFS(vector<int> adj[], vector<bool>&visited,int u, int parent){
        visited[u]=true;
        
        for(int &v : adj[u]){
            if(v==parent) continue;
            if(visited[v]==true) return true;
            if(iscycleDFS(adj,visited,v,u)==true){
                return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        
        for(int i=0;i<V;i++){
            
            if(!visited[i] && iscycleDFS(adj,visited,i,-1)){
                return true;
            }
        }
        return false;
    }
};
