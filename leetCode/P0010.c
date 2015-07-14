

bool isMatch(char* s, char* p) {
	if(NULL == s && NULL == p)
		return true;
	if(NULL == s && NULL != p)
		return false;
	if(NULL != s && NULL == P)
		return false;
	int len_s = strlen(s);
	int len_p = strlen(p);
	if(len_p == 0 && len_s == 0)
		return true;
	
	int cnt_s = 0,cnt_p = 0;
	int flag = 0;
	while(cnt_p < len_p){
		if(p[cnt_p++] == '*' || flag == 1){
			while(p[cnt_p] != '*' && p[cnt_p] != '.'){
				cnt_p ++;
			}
			while(s[cnt_s] != p[cnt_p]){
				cnt_s ++;
			}
			if(p[cnt_p] == '*'){
				flag = 1;
			}
			
			
		}
		else if(p[cnt_p] == '.'){
			cnt_p ++;
			cnt_s ++;
		}
		else{
			if(s[cnt_s++] != p[cnt_p]++)
				return false;
		}
	}
}