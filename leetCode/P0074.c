bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int start=0,end=matrixRowSize-1;
    int row = 0,mid;
    if(target >= matrix[end][0]){
        row = end;
    }else if(target < matrix[0][0]){
        return false;
    }else{
        while(start < end){
            mid = (start+end+1)/2;
            if(matrix[mid][0] > target){
                end = mid - 1;
            }else{
                start = mid;
            }
        }
        row = start;
    }
    
    start = 0;end = matrixColSize-1;
    while(start < end){
        mid = (end+start)/2;
        if(matrix[row][mid] == target)
            return true;
        else if(matrix[row][mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if(matrix[row][start] == target)
        return true;
    else
        return false;
}