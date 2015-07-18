#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}


int main1(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int i = 0,j=0;
		int src[10000][3];
		while(i < n){
			scanf("%d %d %d",&src[i][0],&src[i][1],&src[i][2]);	
			i ++;
		}
		double area = 0;
		int r;
		for(i=0;i<n;i++){
			area = area + ((double)src[i][2]-(double)src[i][1])/360.0*3.1415926535*(double)src[i][0]*(double)src[i][0];
			for(j=0;j<i;j++){
				if(src[i][1] < src[j][1] && src[i][2] > src[j][2]){
					r = min(src[i][0],src[j][0]);
					area -= ((double)src[j][2]-(double)src[j][1])/360.0*3.1415926535*(double)r*(double)r;
				}
				else if(src[i][1] < src[j][2] && src[i][2] > src[j][2]){
					r = min(src[i][0],src[j][0]);
					area -= ((double)src[j][2]-(double)src[i][1])/360.0*3.1415926535*(double)r*(double)r;
				}
				else if(src[i][1] < src[j][1] && src[i][2] > src[j][1]){
					r = min(src[i][0],src[j][0]);
					area -= ((double)src[i][2]-(double)src[j][1])/360.0*3.1415926535*(double)r*(double)r;
				}
				else if(src[i][1] > src[j][1] && src[i][2] < src[j][2]){
					r = min(src[i][0],src[j][0]);
					area -= ((double)src[i][2]-(double)src[i][1])/360.0*3.1415926535*(double)r*(double)r;
				}
			}
		}
		printf("%lf\n",area);
	}


	return 0;
}