void permuteUnique(vector<int> &nums, vector<bool> &used, vector<int> &current, vector<vector<int>> &result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        // Skip used numbers and duplicate numbers
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
            continue;
        }
        used[i] = true;
        current.push_back(nums[i]);
        permuteUnique(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
    permuteUnique(nums, used, current, result);
    return result;
    }