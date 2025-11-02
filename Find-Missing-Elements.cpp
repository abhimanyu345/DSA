class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int end = nums[nums.size()-1];
        vector<int>list(end+1, 0);

        for(int i=0; i<nums.size(); i++)
        {
            list[nums[i]] = 1;
        }
        for(int i=nums[0]; i<=end; i++)
        {
            if(list[i]==0)
                ans.push_back(i);
        }

        return ans;
    }
};