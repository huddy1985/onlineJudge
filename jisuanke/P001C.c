#include <stdio.h>
#include <string.h>

int main(){	
	char arr[101] = {0};
	while(scanf("%s",arr)!=EOF){
		int len = strlen(arr);
		int i;
		if(len < 10){
            printf("%d",arr[i]-'0');
			for(i=1;i<len;i++)
				printf(" %d",arr[i]-'0');
            printf("\n");
			continue;
		}
	
		int max = (len-9)/2+9;
		char *pMax[100];
		for(i=0; i<100; i++)
			pMax[i] = arr;
		i = max;
		int num[100] = {0};
		while(i > 0){
			char cmax[2] = {0};
			sprintf(cmax,"%d",i);
			pMax[i] = strstr(pMax[i],cmax);
			if(pMax[i] == NULL){
				if(++i > 9){
	 				*pMax[i] = i/10 + '0';
					*(pMax[i]+1) = i%10 + '0';
				}
				else
					*pMax[i] = i + '0';
				pMax[i-1] = arr;
				num[pMax[i] - arr] = 0;
				pMax[i] ++;
			}
			else{
				if(i > 9){
					*pMax[i] = ' ';
					*(pMax[i]+1) = ' ';
				}
				else
					*pMax[i] = ' ';

				num[pMax[i] - arr] = i;
				i --;
			}
		}
		printf("%d",num[0]);
		for(i = 1;i<=len;i++){
			if(num[i] > 0)
				printf(" %d",num[i]);
		}
	}
    return 0;
}