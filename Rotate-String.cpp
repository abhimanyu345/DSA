class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size()!=goal.size())
            return false;
        if(s==goal)
            return true;
            
        int pos = 1;
        while(pos<s.size())
        {
            string temp = s;
            reverse(temp.begin(), temp.begin()+pos);
            reverse(temp.begin()+pos, temp.end());
            reverse(temp.begin(), temp.end());
            if(temp==goal)
                return true;
            pos++;
        }

        return false;
    }
};