void solve(vector<int> &nums, int i, vector<int> &v, set<vector<int>> &s) {
        if(i >= nums.size()) {
            return ;
        }
        v.push_back(nums[i]);
        s.insert(v);
        
        solve(nums, i+1, v, s);
        v.pop_back();
        solve(nums, i+1, v, s);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        set<vector<int>> s;

        solve(nums, 0, v, s);

        vector<vector<int>> ans;
        vector<int> a;
        ans.push_back(a);
        for(auto vec: s) {
            ans.push_back(vec);
        }

        return ans;
    }