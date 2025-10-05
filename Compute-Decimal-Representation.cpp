class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        
        vector<int>arr;
        int base = 0;

        while(n)
        {
            int a = n%10;
            n /= 10;
            if(a!=0)
                arr.push_back((int)((double)a*(pow(10, base))));
            base++;
        }

        reverse(arr.begin(), arr.end());
        return arr;
    }
};