class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
            return ;
        
        vector<string> vec;
        int len = s.size();
        string str = "";
        while(len>0 && s[len-1] == ' ')
            len --;
        int i=0;
        while(i<len && s[i]==' ')
            i ++;
        int flag = 0;
        for(; i<len; i++){
            if(s[i] == ' ' && flag == 0){
                vec.push_back(str);
                str = "";
                flag = 1;
            }else if(s[i] == ' ' && flag == 1){
                continue;
            }else if(s[i] != ' '){
                str += s[i];
                flag = 0;
            }
        }
        vec.push_back(str);
        len = vec.size();
        s = vec[len-1];
        for(int i=len-2; i>=0; i--){
            s += " ";
            s += vec[i];
        }
    }
};