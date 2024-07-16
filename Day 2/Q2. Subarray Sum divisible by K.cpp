int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int remainder = ((sum % k) + k) % k;
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }
            remainderCount[remainder]++;
        }

        return count;
    }