#include <stdio.h>
#include <string.h>
int main(){
	char str[20] = {0};
	while(scanf("%s",&str)!=EOF){
		int year=0,month=0,day=0;
		int len = strlen(str);
		int flag = 0;
		for(int i=0; i<len; i++){
			if(str[i] == '/'){
				flag ++;
				continue;
			}
			if(flag == 0){
				year = year*10 + str[i] - '0';

			}else if(flag == 1){
				month = month*10 + str[i] - '0';
			}else{
				day = day*10 + str[i] - '0';
			}
		}
		int res = 0;
		if(month < 3){
			res = (month-1)*31 + day;
		}else{
			if((year%100==0 || year%4)&&(year%400!=0))
				res += 59;
			else
				res += 60;

			if(month>3)
				res += 31;
			if(month > 4)
				res += 30;
			if(month > 5)
				res += 31;
			if(month > 6)
				res += 30;
			if(month > 7)
				res += 31;
			if(month > 8)
				res += 31;
			if(month > 9)
				res += 30;
			if(month > 10)
				res += 31;
			if(month > 11)
				res += 30;
			res += day;
			
		}
		printf("%d\n",res);

	}


	return 0;
}