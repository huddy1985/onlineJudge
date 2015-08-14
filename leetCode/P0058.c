class Solution {
public:
    int lengthOfLastWord(string s) {
        string::reverse_iterator it;
        int cnt = 0;
        for(it=s.rbegin(); it!=s.rend(); it++){
            if(*it == ' ' && cnt > 0)
                return cnt;
            else if(*it != ' ')
                cnt ++;
        }
        return cnt;
    }
};