bool dfs(vector<int> adj[] , vector<int>& vis , vector<int>& pathvis ,int n){
        vis[n]=1;
        pathvis[n]=1;
        for(auto it:adj[n])
        if(!vis[it]){
            if(dfs(adj , vis , pathvis , it)== true){
                return true;
            }
        }
        else if (pathvis[it]){
            return true;
        }
        
        
        pathvis[n]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V+1,0);
        vector<int> pathvis(V+1,0);
        
        for(int i = 0 ; i<V ; i ++){
            if(!vis[i]){
                if(dfs(adj , vis , pathvis , i)==true){
                    return true;
                }
            }
        }
        return false;
    }