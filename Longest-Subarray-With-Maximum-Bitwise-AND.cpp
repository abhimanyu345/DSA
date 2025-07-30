class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxi = 0;
        int cnt = 0;
        int n = nums.size();
        int i = 0;

        while(i<n)
        {
            if(nums[i]>maxi)
            {
                int temp = 1;
                maxi = nums[i];
                int j;
                for(j=i+1; j<n; j++)
                {
                    if(nums[j]==maxi)
                        temp++;
                    else
                        break;
                }
                cnt = temp;
                i = j;
            }
            else if(nums[i]==maxi)
            {
                int temp = 1;
                maxi = nums[i];
                int j;
                for(j=i+1; j<n; j++)
                {
                    if(nums[j]==maxi)
                        temp++;
                    else
                        break;
                }
                cnt = max(cnt,temp);
                i = j;
            }
            else
                i++;
        }

        return cnt;
    }
};