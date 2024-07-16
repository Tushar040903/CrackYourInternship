sort(nums.begin(),nums.end());
        int ans;
        int count = 0;

        for(int i=0;i<nums.size();i++) {
            if(ans != nums[i]) {
                count = 0;
            }
            ans = nums[i];
            count++;

            if(count == nums.size()/2+1) return ans;
        }
        return 1;



// Optimized approach 

int majorityElement(const std::vector<int>& nums) {
    // Step 1: Find a candidate for the majority element
    int candidate = 0;
    int count = 0;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    // Step 2: Verify that the candidate is the majority element
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }
    
    if (count > nums.size() / 2) {
        return candidate;
    } else {
        // Since the problem guarantees that a majority element always exists,
        // we won't actually reach this point.
        return -1;
    }
}