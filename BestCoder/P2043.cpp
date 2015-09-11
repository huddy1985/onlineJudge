#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char str[51] = {0};
		scanf("%s",str);
		int len = strlen(str);
		if(len > 16 || len < 8){
			printf("NO\n");
		}else{
			int flag[4] = {0};
			for(int i=0; i<len; i++){
				if(str[i]>='A' && str[i]<='Z')
					flag[0] = 1;
				else if(str[i]>='a' && str[i]<='z')
					flag[1] = 1;
				else if(str[i]>='0' && str[i]<='9')
					flag[2] = 1;
				else
					flag[3] = 1;
			}
			if(flag[0]+flag[1]+flag[2]+flag[3] >= 3)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
