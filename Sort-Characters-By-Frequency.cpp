class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int>mpp;
        for(int i=0; i<s.size(); i++)
            mpp[s[i]]++;
        vector<pair<int, char>>arr;
        for(auto it:mpp)
        {
            arr.push_back({it.second, it.first});
        }

        sort(arr.rbegin(), arr.rend());
        string ans = "";

        for(int i=0; i<arr.size(); i++)
        {
            for(int j=1; j<=arr[i].first; j++)
            {
                ans += arr[i].second;
            }
        }

        return ans;
    }
};