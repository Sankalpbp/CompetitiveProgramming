

bool possible(int n, int row, int col, int board[11][11] ){
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1; i>=0 and j>=0; i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 and j<n; i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    
    return true;
}



void nQueenHelper(int n,int row, int board[11][11]){
    if(row==n){
        //print the board and return

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
    }
        cout<<endl;
        
        return;
    }
    for(int j=0;j<n;j++){
        if(possible(n,row,j,board)){
            board[row][j]=1;
            nQueenHelper(n,row+1,board);
            board[row][j]=0;
        }
    }
    return;
}
void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int board[11][11]={0};
    nQueenHelper(n,0,board);
    
}


