bool isNumber(char* s) {
    if(s == NULL)
        return false;
    int flag=0,point=0,exp=0,space = 0;
    int len = strlen(s);
    int i = 0;
	while(isspace(s[i]))
        i++;
    if(s[i] == '+' || s[i]=='-')
        i++;
    for(; i<len; i++){
        if((s[i]=='+' || s[i]=='-') && exp==1)
            exp = 2;
        else if(space && !isspace(s[i]))
            return false;
        else if(s[i]=='.'){
            if(!point && flag==0 && !exp){
                point = 1;
                flag = 0;
            }else if(!point && flag && !exp){
                point = 2;
                flag = 0;
            }else
                return false;
        }else if(s[i]=='e' || s[i]=='E'){
            if((flag||point==2) && !exp){
                exp = 1;
                flag = 0;
            }else
                return false;
        }
        else if(isdigit(s[i])){
            if(point==1)
                point = 3;
            if(exp==1 || exp==2)
                exp = 3;
            flag ++;
        }else if(isspace(s[i]) && (flag || point)){
            space = 1;
        }else
            return false;
    }
    if(point==1 || exp==1 || exp==2 || (flag==0 && point==0))
        return false;
    return true;
}