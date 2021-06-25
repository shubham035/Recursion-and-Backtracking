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
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
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

int total_alternate=0;



bool isValidRookBishop(int n , int row , int column , char board[][8],char x){
    
        
        int i=row;
        int j=column;
        // since it is bishop only so we have to check diagonals only :
        
        // left diagonals
        
        while(i>=0 && j>=0){
            if(board[i][j]=='B') return false;
            i--;
            j--;
        }
        
        i=row;
        j=column;
        
        while(i>=0 && j<n){
            if(board[i][j]=='B') return false;
            i--;
            j++;
        }
        
        for(int k=0;k<row;k++){
            if(board[k][column]=='R') return false;
        }
        
        return true;

}


bool solveAlternate(int n , int row , char board[][8],char x){
    
    // base case:
    if(n==row){
        
        total_alternate++;
        // print the board:
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
            
        // }
        // cout<<endl;
        
        return false;
    }
    
    // recursive case:
    
    for(int column=0;column<n;column++){
        
        if(isValidRookBishop( n,  row,  column , board , x)){
            
            board[row][column]=x;
            bool solveNextAlternate;
            if(x=='R')
                 solveNextAlternate=solveAlternate(n,row+1,board,'B');
            else{
                solveNextAlternate=solveAlternate(n,row+1,board,'R');
            }
            
            if(solveNextAlternate) return true;
            
            board[row][column]='.';
        }
    }
    
    return false;
}

int main(){
    
    int n;
    n=8;
   //  total_no_of_combinations=0;
   //  total_bishop_combinations=0;
   
   total_alternate=0;
    char board[8][8];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='.';
        }
    }
    
    // solveNQueen(n,0, board);
    // cout<<total_no_of_combinations<<endl;
    
    
    
    // solveNBishop(n,0,board);
    // cout<<total_bishop_combinations<<endl;
   //  cout<<"solved"<<endl;
   
   // int p=4;
   solveAlternate(8,0,board,'R');
   solveAlternate(8,0,board,'B');
   
   cout<<total_alternate<<endl;
    return 0;
}