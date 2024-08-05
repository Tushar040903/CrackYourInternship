int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int src = headID;
        unordered_map<int, list<int>> adj;

        for(int i=0;i<manager.size();i++) {
            adj[manager[i]].push_back(i);
        }

        vector<bool> visited(n, 0);
        queue<pair<int, int>> q; // node , time
        int maxtime = 0;
        visited[src] = true;
        q.push({src, maxtime});

        while(!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            maxtime = max(maxtime, time);
            for(auto nbr: adj[node]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, time + informTime[node]});
                }
            }
        }

        return maxtime;
    }