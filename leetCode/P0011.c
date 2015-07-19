int min(int a,int b)
{
	return a<b?a:b;
}

int maxArea(int* height, int heightSize) {
    int maxarea = min(height[0],height[heightSize-1])*(heightSize-1);
    int start = 0,end = heightSize-1;
	while(start < end){
		int area = min(height[start],height[end])*(end-start);
		if(area > maxarea){
			maxarea = area;
		}
		if(height[start] < height[end])
			start ++;
		else
			end --;
	}
	return maxarea;
}