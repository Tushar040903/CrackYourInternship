vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        queue<int> q;
        vector<int> ans;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int nbr: adj[node]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        
        return ans;
    }