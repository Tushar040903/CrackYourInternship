int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        if(nums.size() == 3) return nums[0]*nums[1]*nums[2];

        int option1 = nums[nums.size()-3]*nums[nums.size()-2]*nums[nums.size()-1];
        int option2 = nums[nums.size()-1]*nums[0]*nums[1];

        return max(option1,option2);   
    }