
bool bfs(char** board, int boardRowSize, int boardColSize, char* word,int n,int row,int col){
    if(n == strlen(word))
        return true;
    int i = 0;
    if(row-1 >= 0 && board[row-1][col]==word[n]){
        board[row-1][col] = 0;
        if(bfs(board,boardRowSize, boardColSize, word,n+1,row-1,col))
            return true;
        board[row-1][col] = word[n];
    }
    if(col+1 < boardColSize && board[row][col+1]==word[n]){
        board[row][col+1] = 0;
        if(bfs(board,boardRowSize, boardColSize, word,n+1,row,col+1))
            return true;
        board[row][col+1] = word[n];
    }
    if(row+1 < boardRowSize && board[row+1][col]==word[n]){
        board[row+1][col] = 0;
        if(bfs(board,boardRowSize, boardColSize, word,n+1,row+1,col))
            return true;
        board[row+1][col] = word[n];
    }
    if(col-1 >= 0 && board[row][col-1]==word[n]){
        board[row][col-1] = 0;
        if(bfs(board,boardRowSize, boardColSize, word,n+1,row,col-1))
            return true;
        board[row][col-1] = word[n];
    }
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if(strlen(word) == 0)
        return true;
    int i,j;
    for(i=0; i<boardRowSize; i++){
        for(j=0; j<boardColSize; j++){
            if(board[i][j] == word[0]){
                board[i][j] = 0;
                if(bfs(board,boardRowSize,boardColSize,word,1,i,j))
                    return true;
                board[i][j] = word[0];
            }
        }
    }
    return false;
}