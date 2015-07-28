class Solution {
public:
    bool isValid(string s) {
        int len = s.size(),i;
        stack<char> stk;
        for(i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stk.push(s[i]);
            else{
                if(stk.empty())
                    return false;
                if((s[i]==')' && '('!= stk.top()) || (s[i]==']' && '['!= stk.top()) || (s[i]=='}' && '{'!= stk.top()))
                    return false;
                stk.pop();
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};