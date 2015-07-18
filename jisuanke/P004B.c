#include <stdio.h>

inline int judge(int nums[],int a,int b){
    int len = b-a+1;
    while(a < b){
        if(nums[a++] != nums[b--])
            return 0;
    }
    return 1;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int nums[20000];
    int i = 0;
    while(i < n){
        scanf("%d",&nums[i++]);
    }
    i = 0;
    while(i < m){
        int a,b;
        scanf("%d %d",&a,&b);
        int j,k,value=0,m;
        for(k=a-1;k<b;k++)
            value += nums[k];
        for(k=2;k<=b-a+1;k++){
            for(j=a-1;j+k<=b;j++){
                if(judge(nums,j,j+k-1)){
                    for(m=j;m<=j+k-1;m++)
                        value += nums[m];
                }
            }
        }
        printf("%d\n",value);
        i++;
    }
    return 0;
}