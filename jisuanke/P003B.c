#include <stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    int value[2000];
    int i = 0;
    while(i < n){
        scanf("%d",&value[i++]);
    }
    int nums[2000][2];
    i = 0;
    int flag[2000] = {0};
    while(i < n-1){
        scanf("%d %d",&nums[i][0],&nums[i][1]);
        flag[nums[i][0]]++;
        flag[nums[i][1]]++;
        i ++;
    }
    int max = 0,max_num = 0;
    for(i=0;i<n-1;i++){
        if(flag[i] > max)
            max = flag[i];
    }
    int res[2000];
    int index = 0;
    for(i=0;i<n-1;i++){
        if(flag[i] > max){
            max = flag[i];
            max_num = i;
        }
    }
    res[0] = max_num+1;
    index ++;
    for(i=0;i<n-1;i++){
        if(nums[i][0] == max_num+1){
            res[index++] = nums[i][1];
        }
        else if(nums[i][1] == max_num+1){
            res[index++] = nums[i][0];
        }
    }
    
    if(index*(index-1)/2 >= value[max_num]){
        printf("%d\n",index);
        printf("%d",res[0]);
        for(i=1;i<index;i++){
            printf(" %d",res[i]);
        }
        printf("\n");
    }else{
        printf("0\n");
    }
    
    return 0;
}