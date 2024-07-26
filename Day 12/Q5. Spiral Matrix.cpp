void dfs(int i, int j, int dir, vector<vector<int>>& matrix,
             vector<vector<int>>& visited, vector<int>& ans) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size() ||
            visited[i][j])
            return;
        visited[i][j] = true;
        ans.push_back(matrix[i][j]);

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int k = 0; k < 4; ++k) {
            int new_dir = (dir + k) % 4;
            int new_i = i + directions[new_dir][0];
            int new_j = j + directions[new_dir][1];
            dfs(new_i, new_j, new_dir, matrix, visited, ans);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<int> ans;

        dfs(0, 0, 0, matrix, visited, ans);

        return ans;
    }