#include <stdio.h>
#include <string.h>
bool isMatch(char* s, char* p) {
	if(NULL == s && NULL == p)
		return true;
	if(NULL == s && NULL != p)
		return false;
	if(NULL != s && NULL == p)
		return false;
	int flag[2] = {-1.-1};
	int len_s = strlen(s);
	int len_p = strlen(p);
	int p_i = 0,s_i = 0;
	while(p_i < len_p && s_i < len_s){
		if(p[p_i] == '.'){
			s_i ++;p_i ++;
		}else if(p[p_i] == '*'){
			flag[1] = p_i+1;
			p_i ++;
			while(p_i < len_p && s_i < len_s){
				if(s[s_i++] == p[p_i]){
					p_i ++;
					flag[0] = s_i;
					break;
				}
			}
			if(s_i == len_s)
				return false;
			else if(p_i == len_p)
				return true;
		}else if(p[p_i] == s[s_i]){
			p_i ++; s_i ++;
		}else if(flag[0] >= 0){
			s_i = flag[0];p_i = flag[1];
			while(p_i < len_p && s_i < len_s){
				if(s[s_i++] == p[p_i]){
					p_i ++;
					flag[0] = s_i;
					break;
				}
			}
			
			if(s_i == len_s)
				return false;
		}else
			return false;
	}
	if(s_i == len_s && p_i == len_p)
		return true;
	else
		return false;
}