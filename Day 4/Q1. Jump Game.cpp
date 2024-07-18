bool canJump(vector<int>& nums) {
                 if (nums.size() < 2) {
            return true;
        }
        int goal = nums.size() - 1;
        for (int i = goal; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;

    }