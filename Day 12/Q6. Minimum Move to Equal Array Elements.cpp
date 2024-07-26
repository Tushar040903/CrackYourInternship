int minMoves2(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        sort(nums.begin(),nums.end());

        int mid = s + (e-s)/2;

        int x = nums[mid];

        int i = 0;
        int ans = 0;
        while(i <= e) {
            ans = ans + abs(x - nums[i]);
            i++;
        }

        return ans;
    }