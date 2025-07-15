class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        unordered_map<int, int>mpp;
        int ans = 0;
        int sum = 0;
        mpp[0] = 1;

        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(mpp.find(sum-k)!=mpp.end())
            {
                ans += mpp[sum-k];
            }
            mpp[sum]++;
        }

        return ans;
    }
};