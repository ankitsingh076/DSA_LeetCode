class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkDFSCycle(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &inRecursion){
        
        visited[u]=true;
        inRecursion[u]=true;
        
        for(int &v : adj[u]){
            if(visited[v]==true){
                if(inRecursion[v]==true){
                    return true;
                }
            }
            else{
                if(checkDFSCycle(adj,v,visited,inRecursion)){
                    return true;
                }
            }
        }
        
        inRecursion[u]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && checkDFSCycle(adj,i,visited,inRecursion)){
                return true;
            }
        }
        
        return false;
    }
};
