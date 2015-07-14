
bool isPalindrome(int x) {
	if(x < 0)
		return false;
	long long xx = (long long)x;
	long long yy = 0;
	int temp;
	temp = xx % 10;
	while((xx /=10) != 0){
		yy = yy*10 + temp;
		temp = xx % 10;
	}
	yy = yy*10 + temp;
	return yy==(long long)x;
}

int main(){

	bool xx = isPalindrome(15552);
	return 0;
}