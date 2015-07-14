#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int reverse(int x) {
	char num[1000] = {0};
	char res[1000] = {0};
	sprintf(num,"%d",x);
	int len = strlen(num);
	int i = 0;
	long long test = 0;
	if(num[0] < '0' || num[0] > '9'){
		res[0] = num[0];
		for(; i < len-1; i++){
			res[i+1] = num[len-i-1];
			test = test*10 + (res[i+1]-'0');
		}
		if(test > (long long)1<<31)
			return 0;
	}
	else{	
		for(; i < len; i++){
			res[i] = num[len-i-1];
			test = test*10 + (res[i]-'0');
		}
		if(test > (long long)1<<31)
			return 0;
	}

	return atoi(res);
}

int main(){

	int xx = reverse(-2147483412);
	return 0;
}