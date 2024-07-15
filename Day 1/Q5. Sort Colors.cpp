void sortColors(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int index = 0;

        while (index <= e) {
            if (nums[index] == 2) {
                swap(nums[index], nums[e]);
                e--;
            } else if (nums[index] == 0) {
                swap(nums[index], nums[s]);
                s++;
                index++;
            } else {
                index++;
            }
        }
    }