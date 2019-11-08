
bool isSafeInColumn(int board[][9],int col,int num){
    for(int i=0;i<9;i++){
        if(board[i][col]==num){
            return false;
        }
    }
    return true;
}

bool isSafeInRow(int board[][9],int row, int num){
    for(int i=0;i<9;i++){
        if(board[row][i]==num){
            return false;
        }
    }
    return true;
}
bool isSafeInGrid(int board[][9],int row,int col,int num){
    row=row-(row%3);
    col=col-(col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[row+i][col+j]==num){
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int board[][9],int row,int col,int num){
    return isSafeInRow(board,row,num)&&isSafeInColumn(board,col,num)&&isSafeInGrid(board,row,col,num);
}

bool findEmptySpace(int board[][9],int &row, int &col){
    int n=9;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    int row,col;
    if(!findEmptySpace(board,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(isSafe(board,row,col,i)){
            board[row][col]=i;
            if(sudokuSolver(board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}
