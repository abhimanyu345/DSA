class Solution {
public:
    bool isValid(string word) {
        
        int n = word.size();
        int con = 0;
        int vow = 0;
        int num = 0;
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        unordered_set<char>st1;
        st1.insert('A');
        st1.insert('E');
        st1.insert('I');
        st1.insert('O');
        st1.insert('U');
        unordered_set<char>st2;
        st2.insert('0');
        st2.insert('1');
        st2.insert('2');
        st2.insert('3');
        st2.insert('4');
        st2.insert('5');
        st2.insert('6');
        st2.insert('7');
        st2.insert('8');
        st2.insert('9');

        if(n<3)
            return false;
        for(int i=0; i<n; i++)
        {
            if(word[i]>=65 && word[i]<=90 || word[i]>=97 && word[i]<=122)
            {
                if(st.find(word[i])!=st.end() || st1.find(word[i])!=st1.end())
                    vow++;
                else
                    con++;
            }
            else if(st2.find(word[i])!=st2.end())
                num++;
            
            else
                return false;
        }

        if(con==0 || vow==0)
            return false;
        return true;


    }
};