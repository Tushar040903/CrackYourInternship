int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int element = n*m;

        priority_queue<int> pq;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                pq.push(matrix[i][j]);
            }
        }
        int x = element - k;

        for(int i=1;i<=x;i++) {
            pq.pop();
        }

        return pq.top();
    }