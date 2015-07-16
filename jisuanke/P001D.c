#include <stdio.h>
#include <string.h>
int main(){
    
    char num[10] = {0};
    while(scanf("%s",num)!=EOF)
    {
        int n;
        scanf("%d",&n);
        if(0 == n){
            printf("0\n");
            continue;
        }
        int i = 0;
        char base[1000][10] = {0};
        while(i < n){
            scanf("%s",base[i++]);
        }
        int res[1000];
        memset(res,-1,1000*sizeof(int));
        int j = 0;
        int cnt = 0;
        int flag = 0;
        for(i=0; i<n; i++){
            for(j=0; j<9; j++){
                if(num[j] != '*' && num[j] != base[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                flag = 0;
                continue;
            }
            res[cnt++] = i;
        }
        
        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)
            printf("%s\n",base[res[i]]);
    }
    
    
    return 0;
}