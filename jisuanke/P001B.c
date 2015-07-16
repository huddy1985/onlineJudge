#include <stdio.h>
typedef struct problem{
    int x;
    int y;
    int t;
}problem;

int location(int s,int t,int time){
    if(s == t)
        return s;
    int loc = time%(2*(t-s));
    if(loc > (t-s))
        return t-(loc-(t-s));
    else
        return s+loc;
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        int s[1000],t[1000];
        int i = 0;
        while(i < n){
            scanf("%d %d",&s[i],&t[i]);
            i ++;
        }
        problem p[1000];
        i = 0;
        while(i < m){
            scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].t);
            i ++;
        }
        int j = 0;
        for(i=0; i<m; i++){
            int out = 0;
            for(j=0; j<n; j++){
                int loc = location(s[j],t[j],p[i].t);
                if(loc>=p[i].x && loc<=p[i].y)
                    out++;
            }
            printf("%d\n",out);
        }
    }

    return 0;
}