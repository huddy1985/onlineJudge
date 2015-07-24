/*
 * 高精度乘法运算
  */
 
 #include <stdio.h>
 int res[2002] = {0};
 
 
 void calculate(char *a,int len_a,char *b,int len_b){
	 int i,j,k;
	 int r = 0;
	 for(i=len_b-1; i>=0; i--){
		 k = len_b-1-i;
		 for(j=len_a-1; j>=0; j--){
			 int temp = (a[j]-'0')*(b[i]-'0') + r + res[k];
			 r = temp/10;
			 res[k++] = temp%10;
		 }
		 res[k] += r;
	 }
 }
 
 
 
 int main(){
	 char a[1001]={0},b[1001]={1001};
	 scanf("%[^\040]",a);
	 scanf("%s",b);

	 
	 int len_a = strlen(a);
	 int len_b = strlen(b);
	 calculate(a,len_a,b,len_b);
	 printf();
	 
	 return 0;
 }