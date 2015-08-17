class Solution {
private:
    string res;
public:
    int getPalindromeLength(string str,int pre,int *s){
        int len = str.size(),cnt1 = 1,cnt2 = 0,i;
        for(i=1;pre-i>=0&&pre+i<len;i++){
            if(str[pre-i] == str[pre+i])
                cnt1 = cnt1 + 2;
            else
                break;
        }
        int s1 = pre-i+1;
        for(i=0;pre-i>=0&&pre+i+1<len;i++){
            if(str[pre-i] == str[pre+i+1])
                cnt2 = cnt2 + 2;
            else
                break;
        }
        int s2 = pre-i+1;
        if(cnt1 > cnt2){
            *s = s1;
            return cnt1;
        }
        else{
            *s = s2;
            return cnt2;
        }
    }
    string longestPalindrome(string s) {
        if(s.empty())
            return res;
        int len = s.size();
        int max_len = 1,start = 0;;
        for(int i=0; i<len; i++){
            int stt = 0;
            int l =getPalindromeLength(s,i,&stt);
            if(l>max_len){
                max_len = l;
                start = stt;
            }
        }
        res = s.substr(start,max_len);
        return res;
    }
};