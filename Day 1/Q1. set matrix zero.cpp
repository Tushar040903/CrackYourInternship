
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> v;

        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                if(matrix[i][j] == 0) {
                    v.insert({i,j});
                }
            }
        }

        for(pair<int,int> p: v) {
            for(int i=0;i<matrix[p.first].size();i++) {
                matrix[p.first][i] = 0;
            }
            for(int i=0;i<matrix.size();i++) {
                matrix[i][p.second] = 0;
            }
        }
    }