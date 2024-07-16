void dfs(int src,unordered_map<int,bool>& visited,vector<int>& ans,vector<int> adj[]) {
        visited[src] = true;
        
        ans.push_back(src);
        
        for(auto nbr: adj[src]) {
            if(!visited[nbr]) {
                dfs(nbr,visited,ans,adj);
            }
        }
    }

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        vector<int> ans;
        
        for(int node=0;node<V;node++) {
            if(!visited[node]) {
                dfs(node,visited,ans,adj);
            }
        }
        
        return ans;
    }