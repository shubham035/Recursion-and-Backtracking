#include<bits/stdc++.h>
using namespace std;

// N QUEEN PROBLEM 
bool isSafe(int board [][10], int i, int j, int n){

// check for column
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
// check for left diagonal
int x=i;
int y=j;
while(x>=0 && y>=0){

    if(board[x][y]==1)
        return false;
    x--;
    y--;
}

// check for right diagonal

x=i;
y=j;

while(x>=0 && y<n){

    if(board[x][y]==1)
        return false;
    x--;
    y++;
}
// now position is safe 

return true;

}

bool solveNQueen(int board[][10],int i, int n){

// base case
    if(i==n){
        // you have succesfully placed all the queens on the board
        // print the board

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(board[i][j]==1){
                cout<<"Q";
            }
            else{
                cout<<".";
            }
        }
        cout<<"\n";
    }
    cout<<"\n \n";
        //return true;

        // hack try to print all combination
        return false;
    }
    // Recursive Case
    // Try to place the queen in the current row and call on the remaning part which will be solved by recursion

    for(int j=0;j<n;j++){
        // check if its valid to place at that index

        if(isSafe(board , i, j,n)){
            // place the queen
            board[i][j]=1;

            bool nextQueenIsPossible=solveNQueen(board,i+1,n);

            if(nextQueenIsPossible){
                return true;
            }
            // means assumption is  false so we put the deafult configuration of board on i,j

            board[i][j]=0; 
        }
    }
// i have search exhaustively and I'am not able to
// find a correct position to put the quuen

    return false; 


     
}


int main(){

    int n;
    cin>>n;

    int board[10][10]={0};

    solveNQueen(board, 0, n);
    return 0;
}

// LEETCODE ACCEPTED SOLUTION 
// 51 N QUEEN



class Solution {
    vector<vector<string> >v;
    
    bool isSafe(vector<vector<int>> & board , int i, int j, int n){
        
        // base case:
        if(i>=n || j>=n) return false;
        
        // check for column
         for(int row=0;row<i;row++){
             if(board[row][j]==1) return false;
         }
        int x=i;
        int y=j;
        
        // check for left diagonal
        
        while(x>=0 && y>=0){
            if(board[x][y]==1)
                return false;
            x--;
            y--;
        }
        
        x=i;
        y=j;
        // check for right diagonal
        while(x>=0 && y<n){
            
            if(board[x][y]==1) return false;
            
            x--;
            y++;
        }
        
        
        return true;
        
    }
    
    bool solveNQueen(vector<vector<int>>&board,int i, int n){
        // base case
        if(i==n){
            // put the board configuration in v
            vector<string >temp;
            
            for(int it=0;it<n;it++){
                string s="";
                for(int j=0;j<n;j++){
                    
                    if(board[it][j]==0){
                        s=s+'.';
                    }
                    else{
                        s=s+'Q';
                    }
                }
                temp.push_back(s);
            }
            
            v.push_back(temp);
            
            return false;
        }
        // recursive case:
        
        for(int j=0;j<n;j++){
            if(isSafe(board,i,j,n)){
                // assumption
                 board[i][j]=1;
                
                bool nextQueenIsPossible=solveNQueen(board,i+1,n);
                if(nextQueenIsPossible) return true;
                
                //backtrack
                board[i][j]=0;  
            }    
        }
        
        return false;
    }
    
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        v.clear();
       vector<vector<int> >board;
        for(int i=0;i<n;i++){
            vector<int> temp(n,0);
            
                board.push_back(temp);
        }
        solveNQueen(board,0,n);
        
        return v;
    }
};