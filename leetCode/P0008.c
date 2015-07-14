#include <string.h>
#include <stdio.h>
int myAtoi(char* str) {
	if(NULL == str)
		return 0;
	int len = strlen(str);
	int i = 0;
	char flag = '+';
	while(i < len){
		if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\r')
			break;
		i ++;
	}
	if(str[i] == '-'){
		flag = '-';
		i ++;
	}
	else if(str[i] == '+'){
		flag = '+';
		i ++;
	}
	else if(str[i] > '9' || str[i] < '0'){
		return 0;
	}
	long res = 0;
	int start = -1;
	for(;i < len; i++){
		if(str[i] > '9' || str[i] < '0')
			break;
		if(str[i] != '0' && start == -1)
			start = i;
		res = res * 10 + str[i] - '0';
		if(i-start > 11 && start != -1)
			return flag=='-'?(-2147483648):(2147483647);
	}
	if(flag != '-' && res > 2147483647)
		return 2147483647;
	else if(flag == '-' && res > 2147483648)
		return -2147483648;
	else
		return flag == '-'?-res:res;
}


int main(){
	int res = myAtoi("9223372036854775809");
	return 0;
}