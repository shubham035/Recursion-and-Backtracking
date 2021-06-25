#include<bits/stdc++.h>
using namespace std;

int total_no_of_combinations;
int total_bishop_combinations;
bool isValid(char board[][8], int row ,int column , int n){
    
    // column
    for(int i=0;i<row;i++){
        if(board[i][column]=='Q') return false;
    }
    
    int x=row;
    int y=column;
    
    // left diagonal
    while(x>=0 && y>=0){
        
        if(board[x][y]=='Q') return false;
        
        x--;
        y--;
    }
    // right diagonal
    
    x=row;
    y=column;
    
    while(x>=0 && y<n){
        if(board[x][y]=='Q') return false;
        x--;
        y++;
    }
    
    return true;
}

bool  solveNQueen(int n ,int row ,  char board[][8]){
    // base case:
    if(row==n){
        
        // print the board:
        
        total_no_of_combinations++;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        // return true;
        // to print all possible combinations 
        return false;
    }
    
    for(int column=0;column<n;column++){
        if(isValid(board,row, column,n)){
            
            // assumption:
            board[row][column]='Q';
            
            bool nextQueenPossible=solveNQueen(n, row+1, board);
            
            if(nextQueenPossible==true) return true;
            
            //
            board[row][column]='.';
        }
        
    }
    
    
    return false;
}


bool isValidBishop( char board[][8], int row , int column ,  int n){
    
    int x=row;
    int y=column;
    
    // left daigonal
    while(x>=0 && y>=0){
        if(board[x][y]=='B') return false;
        x--;
        y--;
    }
    
    x=row;
    y=column;
    
    while(x>=0 && y<n){
        
        if(board[x][y]=='B') return false;
        x--;
        y++;
    }
    
    return true;
}

bool solveNBishop(int n , int row , char board[][8]){
    
    // base case :
    if(row==n){
        total_bishop_combinations++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    
    // recursive case:
    
    for(int column=0;column<n;column++){
        
        if(isValidBishop(board, row,column,n)){
            // assumption:
            board[row][column]='B';
            
            bool nextBishopPossible=solveNBishop(n, row+1, board);
            
            if(nextBishopPossible) return true;
            
            board[row][column]='.';
        }
        
    }
    
    // find all possible combinations and can say no combination is possible
    return false;
}


int main(){
    
    int n;
    n=8;
    total_no_of_combinations=0;
    total_bishop_combinations=0;
    char board[8][8];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='.';
        }
    }
    
    // solveNQueen(n,0, board);
    // cout<<total_no_of_combinations<<endl;
    solveNBishop(n,0,board);
    
    cout<<total_bishop_combinations<<endl;
    cout<<"solved"<<endl;
    return 0;
}