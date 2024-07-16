void dfs(int src,unordered_map<int,bool>& visited,vector<int>& ans,vector<int> adj[]) {
        visited[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!visited[nbr]) {
                dfs(nbr,visited,ans,adj);
            }
        }
        
        ans.push_back(src);
    }
    
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    unordered_map<int,bool> visited;
        vector<int> ans;
        
        for(int node=0;node<V;node++) {
            if(!visited[node]) {
                dfs(node,visited,ans,adj);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
	}