class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // base case: empty subarray
        int sum = 0, result = 0;

        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                result += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;
        }

        return result;
    }
};
