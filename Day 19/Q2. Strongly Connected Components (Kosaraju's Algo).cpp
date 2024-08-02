void dfs(int src, vector<vector<int>>& adj, stack<int> &st, unordered_map<int, bool> &visited) {
    visited[src] = true;
    
    for(auto nbr: adj[src]) {
        if(!visited[nbr]) {
            dfs(nbr, adj, st, visited);
        }
    }
    st.push(src);
}

void dfs2(int src, unordered_map<int, list<int>> &transpose, unordered_map<int, bool> &visited) {
    visited[src] = true;
    
    for(auto nbr: transpose[src]) {
        if(!visited[nbr]) {
            dfs2(nbr, transpose, visited);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj) {
    unordered_map<int, bool> visited;
    stack<int> st;

    // Step 1: Perform a DFS to fill the stack with vertices in the order of finishing times
    for(int node = 0; node < V; node++) {
        if(!visited[node]) {
            dfs(node, adj, st, visited);
        }
    }
    
    // Step 2: Create a transpose graph
    unordered_map<int, list<int>> transpose;
    for(int i = 0; i < adj.size(); i++) {
        for(auto e: adj[i]) {
            transpose[e].push_back(i);
        }
    }
    
    // Step 3: Perform DFS on the transpose graph in the order defined by the stack
    visited.clear();
    int count = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();
        
        if(!visited[node]) {
            dfs2(node, transpose, visited);
            count++;
        }
    }
    
    return count;
}
