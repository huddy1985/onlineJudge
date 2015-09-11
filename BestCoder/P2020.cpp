#include <stdio.h>
#include <algorithm>
using namespace std;
int nums[100] = {0};
bool Compare(int a,int b){
	a = a<0?-a:a;
	b = b<0?-b:b;
	return a>b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(0 == n)
			break;
		for(int i=0; i<n; i++)
			scanf("%d",&nums[i]);
		sort(nums,nums+n,Compare);
		printf("%d",nums[0]);
		for(int i=1;i<n; i++)
			printf(" %d",nums[i]);
		printf("\n");
	}
	return 0;
}