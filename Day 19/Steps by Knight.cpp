bool isSafe(int newx, int newy, int N) {
    return newx >= 0 && newx < N && newy >= 0 && newy < N;
}

// Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    // Code here
    int x = KnightPos[0] - 1;
    int y = KnightPos[1] - 1;

    int destx = TargetPos[0] - 1;
    int desty = TargetPos[1] - 1;

    vector<vector<int>> visited(N, vector<int>(N, 0));
    queue<pair<int, pair<int, int>>> q;
    int step = 0;
    visited[x][y] = true;

    q.push({step, {x, y}});

    int dx[] = {-2, -1, 1, 2, -2, 2, 1, -1};
    int dy[] = {1, -2, -2, -1, -1, 1, 2, 2};

    while (!q.empty()) {
        int currx = q.front().second.first;
        int curry = q.front().second.second;
        step = q.front().first;

        q.pop();

        for (int i = 0; i < 8; i++) {
            int newx = currx + dx[i];
            int newy = curry + dy[i];

            if (newx == destx && newy == desty) return step + 1;

            if (isSafe(newx, newy, N) && !visited[newx][newy]) {
                visited[newx][newy] = 1;
                q.push({step + 1, {newx, newy}});
            }
        }
    }
    return step;
}
