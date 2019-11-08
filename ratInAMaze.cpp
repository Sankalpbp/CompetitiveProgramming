void printSolution(int** solution, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
    
}

void mazeHelper(int maze[][20],int** solution,int n,int x,int y){
    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        printSolution(solution,n);
        solution[x][y]=0;
        return;
    }
    if(x>=n || x<0 || y>=n || y<0 || solution[x][y]==1 || maze[x][y]==0){
        return;
    }
    solution[x][y]=1;
    mazeHelper(maze,solution,n,x+1,y);
    mazeHelper(maze,solution,n,x-1,y);
    mazeHelper(maze,solution,n,x,y+1);
    mazeHelper(maze,solution,n,x,y-1);
    solution[x][y]=0;
}


void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  int** solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i]= new int[n];
    }
    
    mazeHelper(maze,solution,n,0,0);

}
