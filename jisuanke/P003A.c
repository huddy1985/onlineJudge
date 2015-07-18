#include <stdio.h>

void calculate(int *year,int *month,int *day){
    if(*day == 32){
        *day = 1;
        if(*month != 12){
            (*month) ++;
        }
        else{
            (*year) ++;
            *month = 1;
        }
    }
    else if(*day == 31){
        if(*month == 4 || *month==6 || *month==9 || *month ==11){
            *day = 1;
            if(*month != 12){
                (*month) ++;
            }
            else{
                (*year) ++;
                *month = 1;
            }
        }
    }
    else if(*day == 30){
        if(*month == 2){
            *day = 1;(*month) ++;
        }
    }
    else if(*day == 29){
        if(*month == 2 && ((*year)%100==0 || (*year)%4!=0) && (*year)%400!=0){
            *day = 1;(*month)++;
        }
    }
}


int main(){
    int t;
    int nums[10] = {6,2,5,5,4,5,6,3,7,6};
    scanf("%d",&t);
	int k = 0;
    for(k=0;k<t;k++){
        char date[9] = {0};
        int m;
        scanf("%s",date);
        scanf("%d",&m);
        int year = (date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        int month = (date[4]-'0')*10+(date[5]-'0');
        int day = (date[6]-'0')*10+date[7]-'0';
        int cnt = 0;
        int bh = 0,i = 0;
        for(i=0;i<8;i++)
            bh += nums[date[i]-'0'];
        while(1){
            if(bh == m){
                printf("%d\n",cnt);
                break;
            }
            day ++;
            cnt ++;
            calculate(&year,&month,&day);
            if(year == 3000){
                printf("-1\n");
                break;
            }
            bh = nums[year%10]+nums[year/10%10]+nums[year/100%10]+nums[year/1000];
            bh = bh + nums[month%10] + nums[month/10];
            bh = bh + nums[day%10] + nums[day/10];
        }
    }
    
    
    return 0;
}