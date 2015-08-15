bool isPalindrome(char* s) {
    int len = strlen(s);
    int start=0,end=len-1;
    while(start<=end){
        if(!isalnum(s[start]))
            start ++;
        else if(!isalnum(s[end]))
            end --;
        else if(s[start] == s[end] || (isalpha(s[start]) && isalpha(s[end]) && (s[start]+32==s[end] || s[start]==s[end]+32))){
            start ++;
            end --;
        }
        else
            return false;
    }
   
    return true;
}