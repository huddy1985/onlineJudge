class Solution {
private:
    string res;
public:
    string countAndSay(int n) {
        if(0 == n)
            return res;
        if(1 == n)
            return "1";
                
        string str = "1";
        string tmp;
        int i = 0;
        while(--n){
            int len = str.size(),cnt = 1;
            for(i=1; i<len; i++){
                if(str[i] == str[i-1])
                    cnt ++;
                else{
                    char ch[10] = {0};
                    sprintf(ch,"%d",cnt);
                    tmp += ch;
                    tmp += str[i-1];
                    cnt = 1;
                }
            }
            char ch[10] = {0};
            sprintf(ch,"%d",cnt);
            tmp += ch;
            tmp += str[i-1];
            str.clear();
            str = tmp;
            tmp.clear();
        }
        res += str;
        return res;
    }
};