vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        vector<long long int> ans;
        bool flag = 0;
        int count = 0;
        long long int prod = 1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                flag = 1;
                count++;
            }
            else prod = prod * nums[i];
        }
        if(!flag) {
            for(int i=0;i<nums.size();i++) {
                ans.push_back(prod/nums[i]);
            }
        }
        else {
            if(count == 1) {
                for(int i=0;i<nums.size();i++) {
                    if(nums[i] == 0) ans.push_back(prod);
                    else ans.push_back(0);
                }
            }
            else {
                for(int i=0;i<nums.size();i++) {
                    ans.push_back(0);
            }
            }
        }
        return ans;
    }