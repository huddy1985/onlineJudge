#include <stdio.h>
#include <math.h>
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0 && m==0)
			break;
		int delt = n*n-4*m;
		int sqrt_delt = sqrt((double)delt);
		if(sqrt_delt*sqrt_delt == delt && ((n+sqrt_delt)&1)==0){
			printf("Yes\n");
		}else
			printf("No\n");
	}
	return 0;
}