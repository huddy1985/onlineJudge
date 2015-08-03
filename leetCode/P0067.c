class Solution {
private:
    string res;
public:
    string addBinary(string a, string b) {
        int cnt_a = a.size()-1;
        int cnt_b = b.size()-1;
        if(0 == cnt_a+1)
            return b;
        if(0 == cnt_b+1)
            return a;
        char flag = 0;
        while(cnt_a>=0 && cnt_b>=0){
            char chr = (a[cnt_a]-'0')+(b[cnt_b]-'0')+flag;
            if(chr >= 2){
                flag = 1;
                res.insert(res.begin(),(char)(chr-2+'0'));
            }else{
                flag = 0;
                res.insert(res.begin(),(char)(chr+'0'));
            }
            cnt_a --;
            cnt_b --;
        }
        if(cnt_a < 0){
            while(cnt_b>=0){
                char chr = (b[cnt_b]-'0')+flag;
                if(chr >= 2){
                    flag = 1;
                    res.insert(res.begin(),(char)(chr-2+'0'));
                }else{
                    flag = 0;
                    res.insert(res.begin(),chr+'0');
                }
                cnt_b --;
            }
            if(flag)
                res.insert(res.begin(),flag+'0');
        }else{
            while(cnt_a>=0){
                char chr = (a[cnt_a]-'0')+flag;
                if(chr >= 2){
                    flag = 1;
                    res.insert(res.begin(),(char)(chr-2+'0'));
                }else{
                    flag = 0;
                    res.insert(res.begin(),chr+'0');
                }
                cnt_a --;
            }
            if(flag)
                res.insert(res.begin(),flag+'0');
        }
        return res;   
    }
};