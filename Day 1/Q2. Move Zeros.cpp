void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return;
        int first = 0;
        int second = 1;

        while(second<nums.size()) {
            if(nums[first] != 0) {
                first++;
                second = first+1;
            }
            else {
                if(nums[second] == 0) {
                    second++;
                }
                else {
                    swap(nums[first],nums[second]);
                }
            }
        }
    }

