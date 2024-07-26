void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &visited) {
        
        if(i<0 || i>=mat.size() || j<0 || j>=mat[i].size() || visited[i][j] || mat[i][j] == 'X') return ;
        
        visited[i][j] = true;
        
        dfs(i,j-1,mat,visited);
        dfs(i,j+1,mat,visited);
        dfs(i-1,j,mat,visited);
        dfs(i+1,j,mat,visited);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> visited(n, vector<bool>(m,0));
        vector<vector<char>> ans = mat;
        
        for(int j=0;j<m;j++) {
            if(!visited[0][j] && mat[0][j] == 'O') {
                dfs(0,j,mat,visited);
            }
            if(!visited[n-1][j] && mat[n-1][j] == 'O') {
                dfs(n-1,j,mat,visited);
            }
        }
        for(int i=0;i<n;i++) {
            if(!visited[i][0] && mat[i][0] == 'O') {
                dfs(i,0,mat,visited);
            }
            if(!visited[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i,m-1,mat,visited);
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(visited[i][j] == 0) ans[i][j] = 'X';
                else ans[i][j] = 'O';
            }
        }
        
        return ans;
        
    }