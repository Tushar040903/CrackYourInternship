sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> output;
        
        for(int k=0;k<=nums.size()-3;k++) {
            int i = k+1;
            int j = nums.size()-1;

            while(i<j) {

            vector<int> temp;
            int sum = nums[i]+nums[j]+nums[k];

            if(sum >0) {
                j--;
            }
            else if(sum < 0) {
                i++;
            }
            else if(sum == 0) {
                temp.push_back(nums[k]);
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                ans.insert(temp);
                i++;
                j--;
            }
        }
        }
        for(auto triplets : ans)
            output.push_back(triplets);
        return output;