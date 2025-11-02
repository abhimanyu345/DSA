class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        
        vector<long long>com;
        sort(nums.begin(), nums.end());
        int one = 0;
        int two = 1;
        int three = nums.size()-2;
        int four = nums.size()-1;

        if(two!=three)
        {
            com.push_back(abs(1ll*nums[one]*nums[four]));
            com.push_back(abs(1ll*nums[one]*nums[two]));
            com.push_back(abs(1ll*nums[two]*nums[three]));
            com.push_back(abs(1ll*nums[three]*nums[four]));
            com.push_back(abs(1ll*nums[one]*nums[three]));
            com.push_back(abs(1ll*nums[two]*nums[four]));
        }
        else
        {
            com.push_back(abs(1ll*nums[one]*nums[four]));
            com.push_back(abs(1ll*nums[one]*nums[two]));
            com.push_back(abs(1ll*nums[four]*nums[two]));
        }

        sort(com.begin(), com.end());
        return 1e5*com[com.size()-1];
    }
};