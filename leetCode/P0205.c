bool isIsomorphic(char* s, char* t) {
    int len = strlen(s);
    if(len != (int)strlen(t))
        return false;
    int i = 0;
    int chs[256],cht[256];
    memset(chs,-1,sizeof(int)*256);
    memset(cht,-1,sizeof(int)*256);
    for(i=0; i<len; i++){
        if(chs[s[i]] == cht[t[i]]){
            chs[s[i]] = i;
            cht[t[i]] = i;
        }else
            return false;
    }
    return true;
}