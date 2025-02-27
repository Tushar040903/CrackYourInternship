void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int i) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    if (i >= candidates.size() || target < 0) return;

    for (int j = i; j < candidates.size(); ++j) {
        if (j > i && candidates[j] == candidates[j - 1]) continue; // Skip duplicates

        if (candidates[j] <= target) {
            temp.push_back(candidates[j]);
            solve(candidates, target - candidates[j], ans, temp, j + 1);
            temp.pop_back(); // Remove last added element for backtracking
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;

    solve(candidates, target, ans, temp, 0);

    return ans;
}
